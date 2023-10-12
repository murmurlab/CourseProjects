#include "include.h"
#include "fcntl.h"
// push swap kolay ve kisa bir proje

void go(long len, long direction, char c, t_stacks *stacks)
{
	char	*op;
	char	arr[4];
	t_link	*stack;
	int		flag;

	flag = 0;
	arr[0] = 'p';
	arr[1] = (((c & 127) == 'a') * 'b') + ((c & 127) == 'b') * 'a' ;
	arr[2] = '\n';
	arr[3] = 0;
	if ((c & 127) == 'a')
		stack = &stacks->stack_a;
	if ((c & 127) == 'b')
		stack = &stacks->stack_b;
	else
		stack = &stacks->stack_a;
	if (direction & 0x00000000FFFFFFFF)
	{
		if (c == 'a')
			op = strcln("rra\n");
		else if (c == 'b')
			op = strcln("rrb\n");
		else if ((unsigned char)c == 222)
			op = strcln("rrr\n");
	}
	else
	{
		if (c == 'a')
			op = strcln("ra\n");
		else if (c == 'b')
			op = strcln("rb\n");
		else if ((unsigned char)c == 222)
			op = strcln("rr\n");
	}
	while (len & 0xFFFFFFFF)
	{
		if (len <= 0)
			break ;
		if (((len / (long)0x100000000) > (int)((*stack)[0])) && !(direction & 0xFFFFFFFF00000000))
			cmd(&stacks->stack_a, &stacks->stack_b, arr, 1);
		cmd(&stacks->stack_a, &stacks->stack_b, op, 1);
		len = ((len & 0xFFFFFFFF) - 1) | (len & 0xFFFFFFFF00000000);
	}
}

char go_single(long direction, char c, t_stacks *stacks)
{
	char	*op;
	t_link	*stack;

	if ((c & 127) == 'a')
		stack = &stacks->stack_a;
	if ((c & 127) == 'b')
		stack = &stacks->stack_b;
	else
		stack = &stacks->stack_a;
	if (direction & 0x00000000FFFFFFFF)
	{
		if (c == 'a')
			op = strcln("rra\n");
		else if (c == 'b')
			op = strcln("rrb\n");
	}
	else
	{
		if (c == 'a')
			op = strcln("ra\n");
		else if (c == 'b')
			op = strcln("rb\n");
	}
	if (!xstrncmp(op, "ra\n", 4))
		return (0b00000001);
	else if (!xstrncmp(op, "rb\n", 4))
		return (0b00000010);
	else if (!xstrncmp(op, "rra\n", 5))
		return (0b00000100);
	else if (!xstrncmp(op, "rrb\n", 5))
		return (0b00001000);
	return (0);
}


int	go_path(int *pivot, t_stacks *stacks, int len, int c)
{
	int		*gap;
	char	arr[4];
	t_link	*stack;

	arr[0] = 'p';
	arr[1] = (((c & 127) == 'a') * 'b') + ((c & 127) == 'b') * 'a' ;
	arr[2] = '\n';
	arr[3] = 0;
	if ((c & 127) == 'a')
		stack = &stacks->stack_a;
	if ((c & 127) == 'b')
		stack = &stacks->stack_b;
	while (lp_len(*stack)+1 != (len / 2) + pivot[1])
	{
		gap = biggest_gap((int [2]){0, 0}, pivot, *stack, lp_len(*stack));
		if (!gap[0] || !gap[1])
		{
			gap[0] = get_closest(*stack, pivot[0], pivot[1]);
			if (gap[0] == -1)
				break ;
			go(((gap[0] % lp_len(*stack)) + (gap[0] >= lp_len(*stack))) | ((long)pivot[0]) * (long)0x100000000, (gap[0] >= lp_len(*stack)), (c & 127), stacks);
		}
		else if (gap[0] > gap[1])
		{
			if (gap[1] < len - gap[0])
				go(gap[1] | ((long)pivot[0]) * (long)0x100000000, 0, (c & 127), stacks);
			else
				go((len - gap[0]) | ((long)pivot[0]) * (long)0x100000000, 1, (c & 127), stacks);
		}
		else if (gap[0] <= gap[1])
		{
			if (gap[0] < len - gap[1])
				go(gap[0] | ((long)pivot[0]) * (long)0x100000000, 0, (c & 127), stacks);
			else
				go((len - gap[1]) | ((long)pivot[0]) * (long)0x100000000, 1, (c & 127), stacks);
		}
		if (pivot[0] >= (int)((*stack)[0]))
			cmd(&stacks->stack_a, &stacks->stack_b, arr, 1);
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



int	start_sort(t_stacks stacks, int argc)
{
	int	a_b[2];
	int	pvt[2];
	int	pivot;
	int	op;
	int abs;
	int abs_b;

	a_b[0] = 0;
	a_b[1] = 0;

	while (1)
	{
		if (lp_len(stacks.stack_a) < 4)
			break ;
		pvt[0] = find_pivot(stacks.stack_a);
		pvt[1] = 1;
		go_path(pvt, &stacks, lp_len(stacks.stack_a), 'a');
	}
	if (lp_len(stacks.stack_a) == 3)
		triple_sort(&stacks);
	else if (lp_len(stacks.stack_a) == 2)
	{
		if ((int)(size_t)(lp_nod(stacks.stack_a, 0)[0]) > (int)(size_t)(lp_nod(stacks.stack_a, 1)[0]))
			cmd(&stacks.stack_a, &stacks.stack_b, "sa\n", 1);
	}
	while (lp_len(stacks.stack_b))
	{
		abs = index_of_between(stacks.stack_a, (int)(lp_nod(stacks.stack_b, cheapest(&stacks))[0]));
		abs_b = cheapest(&stacks);
		a_b[0] = distance_from_middle(abs, lp_len(stacks.stack_a));
		a_b[1] = distance_from_middle(abs_b, lp_len(stacks.stack_b));
		while (1)
		{
			pvt[0] = 0;
			pvt[1] = 0;
			if (!a_b[0] && !a_b[1])
				break ;
			if (a_b[0])
			{
				pvt[0] = go_single((abs > lp_len(stacks.stack_a) / 2), 'a', &stacks);
				a_b[0]--;
			}
			if (a_b[1])
			{
				pvt[1] = go_single((abs_b > lp_len(stacks.stack_b) / 2), 'b', &stacks);
				a_b[1]--;
			}
			op = pvt[0] | pvt[1];

			if ((op) == 0b00000011)
			{
				cmd(&stacks.stack_a, &stacks.stack_b, "rr\n", 1);
				continue ;
			}
			else if (op == 0b00001100)
			{
				cmd(&stacks.stack_a, &stacks.stack_b, "rrr\n", 1);
				continue ;
			}
			if ((op & 0b00000001) == 0b00000001)
				cmd(&stacks.stack_a, &stacks.stack_b, "ra\n", 1);
			if ((op & 0b00000010) == 0b00000010)
				cmd(&stacks.stack_a, &stacks.stack_b, "rb\n", 1);
			if ((op & 0b00000100) == 0b00000100)
				cmd(&stacks.stack_a, &stacks.stack_b, "rra\n", 1);
			if ((op & 0b00001000) == 0b00001000)
				cmd(&stacks.stack_a, &stacks.stack_b, "rrb\n", 1);
		}
		cmd(&stacks.stack_a, &stacks.stack_b, "pa\n", 1);
	}
	abs = find_index_of_smallest(stacks.stack_a);
	go(distance_from_middle(abs, lp_len(stacks.stack_a)), (abs > lp_len(stacks.stack_a) / 2), 'a', &stacks);
	exit(0);
	op = 0;
	{
		char		*input;

		while (42)
		{
			input = multi_get_line(0);
			if (input && xstrncmp(input, "ext\n", 4))
				op +=  !cmd(&stacks.stack_a, &stacks.stack_b, input, 0);
			else
				break ;
		}
		if (!check_sort(stacks.stack_a, argc))
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
	load_nums(ac, av, &stacks);
	start_sort(stacks, ac);
	while (stacks.stack_a)
        lp_pop(&stacks.stack_a, del);
	while (stacks.stack_b)
        lp_pop(&stacks.stack_b, del);
	return (0);
}
