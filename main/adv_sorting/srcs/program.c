#include "include.h"
#include "fcntl.h"
// push swap kolay ve kisa bir proje

void	assign_op(t_utils *utils)
{
	if (utils->direction & 0x00000000FFFFFFFF)
	{
		if (utils->c == 'a')
			utils->op = strcln("rra\n");
		else if (utils->c == 'b')
			utils->op = strcln("rrb\n");
		else if ((unsigned char)utils->c == 222)
			utils->op = strcln("rrr\n");
	}
	else
	{
		if (utils->c == 'a')
			utils->op = strcln("ra\n");
		else if (utils->c == 'b')
			utils->op = strcln("rb\n");
		else if ((unsigned char)utils->c == 222)
			utils->op = strcln("rr\n");
	}
}

void go(long len, long direction, char c, t_stacks *stacks)
{
	t_utils	utils;

	utils.flag = 0;
	utils.direction = direction;
	utils.c = c;
	utils.arr[0] = 'p';
	utils.arr[1] = (((c & 127) == 'a') * 'b') + ((c & 127) == 'b') * 'a' ;
	utils.arr[2] = '\n';
	utils.arr[3] = 0;
	if ((c & 127) == 'a')
		utils.stack = &stacks->stack_a;
	if ((c & 127) == 'b')
		utils.stack = &stacks->stack_b;
	assign_op(&utils);
	while (len & 0x00000000FFFFFFFF)
	{
		if ((len & 0x00000000FFFFFFFF) <= 0)
			break ;
		if (((len / (long)0x100000000) > (int)((*(utils.stack))[0])) && 
			!(direction & 0xFFFFFFFF00000000))
			cmd(&stacks->stack_a, &stacks->stack_b, utils.arr, 1);
		else
			cmd(&stacks->stack_a, &stacks->stack_b, utils.op, 1);
		len = ((len & 0xFFFFFFFF) - 1) | (len & 0xFFFFFFFF00000000);
	}
}

char go_single(long direction, char c, t_stacks *stacks)
{
	char	*op;
	t_link	*stack;
	t_utils	utils;

	utils.direction = direction;
	utils.c = c;
	utils.op = op;
	if ((c & 127) == 'a')
		stack = &stacks->stack_a;
	if ((c & 127) == 'b')
		stack = &stacks->stack_b;
	else
		stack = &stacks->stack_a;
	assign_op(&utils);
	if (!xstrncmp(utils.op, "ra\n", 4))
		return (0b00000001);
	else if (!xstrncmp(utils.op, "rb\n", 4))
		return (0b00000010);
	else if (!xstrncmp(utils.op, "rra\n", 5))
		return (0b00000100);
	else if (!xstrncmp(utils.op, "rrb\n", 5))
		return (0b00001000);
	return (0);
}


int	go_path(t_sort *sort , int len, int c)
{
	int		*gap;
	char	arr[4];
	t_link	*stack;

	arr[0] = 'p';
	arr[1] = (((c & 127) == 'a') * 'b') + ((c & 127) == 'b') * 'a' ;
	arr[2] = '\n';
	arr[3] = 0;
	if ((c & 127) == 'a')
		stack = &sort->stacks->stack_a;
	if ((c & 127) == 'b')
		stack = &sort->stacks->stack_b;
	while (lp_len(*stack)+1 != (len / 2) + sort->pvt[1] && lp_len(*stack) > 3)
	{
		gap = biggest_gap((int [2]){0, 0}, sort->pvt, *stack, lp_len(*stack));
		if (!gap[0] || !gap[1])
		{
			gap[0] = get_closest(*stack, sort->pvt[0], sort->pvt[1]);
			if (gap[0] == -1)
				break ;
			go(((gap[0] % lp_len(*stack)) + (gap[0] >= lp_len(*stack))) |
			((long)sort->pvt[0]) * (long)0x100000000, (gap[0] >= lp_len(*stack)),
			(c & 127), sort->stacks);
		}
		else if (gap[0] > gap[1])
		{
			if (gap[1] < len - gap[0])
				go(gap[1] | ((long)sort->pvt[0]) * (long)0x100000000, 0, (c & 127),
				sort->stacks);
			else
				go((len - gap[0]) | ((long)sort->pvt[0]) * (long)0x100000000, 1,
				(c & 127), sort->stacks);
		}
		else if (gap[0] <= gap[1])
		{
			if (gap[0] < len - gap[1])
				go(gap[0] | ((long)sort->pvt[0]) * (long)0x100000000, 0, (c & 127),
				sort->stacks);
			else
				go((len - gap[1]) | ((long)sort->pvt[0]) * (long)0x100000000, 1,
				(c & 127), sort->stacks);
		}
		if (sort->pvt[0] >= (int)((*stack)[0]))
			cmd(&sort->stacks->stack_a, &sort->stacks->stack_b, arr, 1);
	}
	return (1);
}



void	triple_sort(t_stacks *stacks)
{
	int	a;
	int	b;
	int	c;

	a = (int)(size_t)(lp_nod(stacks->stack_a, 0)[0]);
	b = (int)(size_t)(lp_nod(stacks->stack_a, 1)[0]);
	c = (int)(size_t)(lp_nod(stacks->stack_a, 2)[0]);

	if (a < b && b > c && a < c) // 1 3 2
	{
		cmd(&stacks->stack_a, &stacks->stack_b, "sa\n", 1);
		cmd(&stacks->stack_a, &stacks->stack_b, "ra\n", 1);
	}
	else if (a > b && b < c && a < c) // 2 1 3
		cmd(&stacks->stack_a, &stacks->stack_b, "sa\n", 1);
	else if (a > b && b > c && a > c) // 3 2 1
	{
		cmd(&stacks->stack_a, &stacks->stack_b, "sa\n", 1);
		cmd(&stacks->stack_a, &stacks->stack_b, "rra\n", 1);
	}
	else if (a < b && b > c && a > c) // 2 3 1
		cmd(&stacks->stack_a, &stacks->stack_b, "rra\n", 1);
	else if (a > b && b < c && a > c) // 3 1 2
		cmd(&stacks->stack_a, &stacks->stack_b, "ra\n", 1);
}


int	calc_moves(t_stacks *stacks, int index)
{
	int	val;
	int	move_a;
	int	move_b;

	move_b = index;
	val = (int)(lp_nod(stacks->stack_b, index)[0]);
	move_a = index_of_between(stacks->stack_a, val);
	move_a = distance_from_middle(move_a, lp_len(stacks->stack_a));
	move_b = distance_from_middle(move_b, lp_len(stacks->stack_b));
	return (move_a + move_b);
}


int	cheapest(t_stacks *stacks)
{
	int	index;
	int	len;
	int	cheapest[2];

	index = 0;
	len = lp_len(stacks->stack_b);
	cheapest[0] = 0x7FFFFFFF;
	while (index < len)
	{
		if (cheapest[0] > calc_moves(stacks, index))
			(cheapest[0] = calc_moves(stacks, index), cheapest[1] = index);
		index++;
	}
	return (cheapest[1]);
}

void	prepare()
{

}

void	assign_all()
{

}

int	start_sort(t_stacks stacks, int argc)
{
	t_sort	sort;

	sort.stacks = &stacks;
	sort.a_b[0] = 0;
	sort.a_b[1] = 0;

	while (1)
	{
		if (lp_len(sort.stacks->stack_a) < 4)
			break ;
		sort.pvt[0] = find_pivot(sort.stacks->stack_a);
		sort.pvt[1] = 1;
		go_path(&sort, lp_len(sort.stacks->stack_a), 'a');
	}
	if (lp_len(sort.stacks->stack_a) == 3)
		triple_sort(sort.stacks);
	else if (lp_len(sort.stacks->stack_a) == 2)
	{
		if ((int)(size_t)(lp_nod(sort.stacks->stack_a, 0)[0]) >
			(int)(size_t)(lp_nod(sort.stacks->stack_a, 1)[0]))
			cmd(&sort.stacks->stack_a, &sort.stacks->stack_b, "sa\n", 1);
	}
	while (lp_len(sort.stacks->stack_b))
	{
		sort.abs = index_of_between(sort.stacks->stack_a,
		(int)(lp_nod(sort.stacks->stack_b, cheapest(sort.stacks))[0]));
		sort.abs_b = cheapest(sort.stacks);
		sort.a_b[0] = distance_from_middle(sort.abs, lp_len(sort.stacks->stack_a));
		sort.a_b[1] = distance_from_middle(sort.abs_b,
		lp_len(sort.stacks->stack_b));
		sort.a_b[2] = 0;
		while (1)
		{
			sort.pvt[0] = 0;
			sort.pvt[1] = 0;
			if (!sort.a_b[0] && !sort.a_b[1])
				break ;
			if (sort.a_b[0])
			{
				sort.pvt[0] = go_single((sort.abs > lp_len(sort.stacks->stack_a) / 2), 'a', sort.stacks);
				sort.a_b[0]--;
			}
			if (sort.a_b[1])
			{
				sort.pvt[1] = go_single((sort.abs_b > lp_len(sort.stacks->stack_b) / 2), 'b',
									sort.stacks);
				sort.a_b[1]--;
			}
			sort.op = sort.pvt[0] | sort.pvt[1];

			if ((sort.op) == 0b00000011)
			{
				cmd(&sort.stacks->stack_a, &sort.stacks->stack_b, "rr\n", 1);
				continue ;
			}
			else if (sort.op == 0b00001100)
			{
				cmd(&sort.stacks->stack_a, &sort.stacks->stack_b, "rrr\n", 1);
				continue ;
			}
			if ((sort.op & 0b00000001) == 0b00000001)
				cmd(&sort.stacks->stack_a, &sort.stacks->stack_b, "ra\n", 1);
			if ((sort.op & 0b00000010) == 0b00000010)
				cmd(&sort.stacks->stack_a, &sort.stacks->stack_b, "rb\n", 1);
			if ((sort.op & 0b00000100) == 0b00000100)
				cmd(&sort.stacks->stack_a, &sort.stacks->stack_b, "rra\n", 1);
			if ((sort.op & 0b00001000) == 0b00001000)
				cmd(&sort.stacks->stack_a, &sort.stacks->stack_b, "rrb\n", 1);
		}
		cmd(&sort.stacks->stack_a, &sort.stacks->stack_b, "pa\n", 1);
	}
	sort.abs = find_index_of_smallest(sort.stacks->stack_a);
	go(distance_from_middle(sort.abs, lp_len(sort.stacks->stack_a)), (sort.abs >
	lp_len(sort.stacks->stack_a) / 2) | 0x0000000100000000, 'a', sort.stacks);
	exit(0);
	op = 0;
	{
		char		*input;

		while (42)
		{
			input = multi_get_line(0);
			if (input && xstrncmp(input, "ext\n", 4))
				op +=  !cmd(&sort.stacks->stack_a, &sort.stacks->stack_b, input, 0);
			else
				break ;
		}
		if (!check_sort(sort.stacks->stack_a, argc))
			p("[OK!]\n");
		else
			p("[KO!]\n");
	}
	return (0);
}

int	main(int ac, char *av[])
{
	t_stacks	stacks;
	char		**av2;

	(void)av;
	(void)ac;
	stacks.stack_a = NULL;
	stacks.stack_b = NULL;
	// av2 = file_load("./aww");
	// load_nums(tablen(av2), av2, &stacks);
	load_nums(ac, av, &stacks, 1);
	start_sort(stacks, ac);
	while (stacks.stack_a)
        lp_pop(&stacks.stack_a, del);
	while (stacks.stack_b)
        lp_pop(&stacks.stack_b, del);
	return (0);
}
