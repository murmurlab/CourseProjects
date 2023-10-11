#include "include.h"
#include "fcntl.h"
// push swap kolay ve kisa bir proje






int	find_pivot(t_link stack);

int s(t_link *stack, int a, int b)
{
	t_link  tmp;

    if (lp_len(*stack) < 1)
        return (1);
    tmp = lp_nod(*stack, b);
    lp_swap(lp_nod(*stack, a), lp_nod(*stack, b));
    *stack = tmp;
    return (0);
}

int m(t_link *stack_a, t_link *stack_b)
{
    void    *data;

    if (lp_len(*stack_b) < 1)
        return (1);
    data = (*stack_b)[0];
    lp_pop(stack_b, del);
    lp_push(stack_a, lp_new(data));
    return (0);
}

int mv(t_link *stack)
{
	t_link  tmp;
	t_link  tmp2;

    if (lp_len(*stack) < 1)
        return (1);
    tmp = lp_nod(*stack, 1);
    tmp2 = lp_nod(*stack, 0);
    lp_add(stack, (*stack));
    tmp2[1] = 0;
    tmp[2] = 0;
    *stack = tmp;
    return (0);

}

int rmv(t_link *stack)
{
	t_link  tmp;

    if (lp_len(*stack) < 1)
        return (1);
    lp_push(stack, lp_new(lp_end(*stack)[0]));
    tmp = ((t_link)(lp_end(*stack)[2]));
    lp_del(lp_end(*stack), del);
    tmp[1] = 0;
    return (0);
}

int cmd(t_link *stack_a, t_link *stack_b, char *cmd, int print)
{
    int ret;

    ret = 1;
    if (!xstrncmp(cmd, "sa\n", 3))
        ret = ((print && write(1, "sa\n", 3)), s(stack_a, 0, 1));
    else if (!xstrncmp(cmd, "sb\n", 3))
        ret = ((print && write(1, "sb\n", 3)), s(stack_b, 0, 1));
    else if (!xstrncmp(cmd, "ss\n", 3))
        ret = ((print && write(1, "ss\n", 3)), s(stack_b, 0, 1) + s(stack_a, 0, 1));
    else if (!xstrncmp(cmd, "pa\n", 3))
        ret = ((print && write(1, "pa\n", 3)), m(stack_a, stack_b));
    else if (!xstrncmp(cmd, "pb\n", 3))
        ret = ((print && write(1, "pb\n", 3)), m(stack_b, stack_a));
    else if (!xstrncmp(cmd, "ra\n", 3))
        ret = ((print && write(1, "ra\n", 3)), mv(stack_a));
    else if (!xstrncmp(cmd, "rb\n", 3))
        ret = ((print && write(1, "rb\n", 3)), mv(stack_b));
    else if (!xstrncmp(cmd, "rrr\n", 4))
        ret = ((print && write(1, "rrr\n", 4)), rmv(stack_b) + rmv(stack_a));
    else if (!xstrncmp(cmd, "rra\n", 4))
        ret = ((print && write(1, "rra\n", 4)), rmv(stack_a));
    else if (!xstrncmp(cmd, "rrb\n", 4))
        ret = ((print && write(1, "rrb\n", 4)), rmv(stack_b));
    else if (!xstrncmp(cmd, "rr\n", 3))
        ret = ((print && write(1, "rr\n", 3)), mv(stack_b) + mv(stack_a));
    else if (!xstrncmp(cmd, "pvt\n", 4))
        return (p("pvt_a: %d\npvt_b: %d\n", find_pivot(*stack_a), find_pivot(*stack_b)), 1);
    if (ret)
        p("Error:\ncommand was not executed %d\n", ret);
    return (ret);
}














t_link	bubble_sort(t_link stack)
{
	t_link	tmp;
	int		flag;
	t_link	bash;

	bash = stack;
	flag = 0;
	tmp = stack;
	while (1)
	{
		while (tmp)
		{
			if (!tmp[1])
				break ;
			if (tmp[0] > ((t_link)(tmp[1]))[0])
			{
				if (bash == tmp)
					bash = tmp[1];
				lp_swap(tmp, tmp[1]);
				flag = 1;
			}
			tmp = tmp[1];
		}
		if (!flag)
			break ;
		tmp = bash;
		flag = 0;
	}
	return (bash);
}

int	find_pivot(t_link stack)
{
	t_link	tmp_lp;
	int		ret;

	if (!stack)
		return (0);
	if (lp_len(stack) < 2)
		return (0);
	tmp_lp = lp_dup(stack);
	tmp_lp = bubble_sort(tmp_lp);
	// print_links(tmp_lp, 0);
	ret = (int)(size_t)(lp_nod(tmp_lp, lp_len(tmp_lp) / 2)[0]);
	while (tmp_lp)
        lp_pop(&tmp_lp, del);
	return (ret);
}

int	*biggest_gap(int *zone, int *pivot, t_link stack, int len)
{
	int	*ret;
	int	tmp;
	int target_len;
	int	stock_zone;

	stock_zone = zone[0];
	target_len = ft_fabs(((zone[1] <= zone[0]) * len) - ft_fabs(zone[1] - zone[0]));
	ret = callocate(sizeof(int), 2);
	ret[0] = zone[0];
	ret[1] = -1;
	tmp = 0;
	while (target_len-- > -1)
	{
		
		if (
			(
				((int)(size_t)(lp_nod(stack, zone[0])[0]) < pivot[0])
			)
			|| zone[0] == stock_zone)
		{
			if (ret[1] != -1)
			{
				// p("<%d %d>\n", tmp, zone[0]);
				if (ret[0] != -1 && ret[1] != -1 && ft_fabs(((ret[1] <= ret[0]) * len) - ft_fabs(ret[1] - ret[0])) < ft_fabs(((zone[0] <= tmp) * len) - ft_fabs(zone[0] - tmp)))
				{
					// p("x: %d\n", tmp);
					ret[0] = tmp;
					ret[1] = zone[0];
				}
			}
			else if (ret[0] != zone[0])
				ret[1] = zone[0];
			tmp = zone[0];
			// p("[%d %d %d]\n", zone[0], ret[0], ret[1]);
		}
		// p("num: %d\n", zone[0]);
		zone[0]++;
		if (zone[0] == (len))
			zone[0] = 0;
	}
	return (ret);
}

int	find_smallest(t_link stack)
{
	int	ret;

	ret = (int)stack[0];
	while (stack)
	{
		if ((int)stack[0] < ret)
			ret = (int)stack[0];
		stack = stack[1];
	}
	return (ret);
}

int	find_2nd_biggest(t_link stack)
{
	int	ret;
	int	ret2;

	ret = (int)stack[0];
	ret2 = (int)stack[0];
	while (stack)
	{
		if ((int)stack[0] > ret)
		{
			ret2 = ret;
			ret = (int)stack[0];
		}
		if ((int)stack[0] < ret && (int)stack[0] > ret2)
			ret2 = (int)stack[0];
		stack = stack[1];
	}
	return (ret2);
}

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
	// p("%d\n", len);
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
		// p("%d\n", len & 0xFFFFFFFF);
		// if (flag)
		// 	len = ((len & 0xFFFFFFFF) - flag) | (len & 0xFFFFFFFF00000000);
		if (len <= 0)
			break ;
		if (((len / (long)0x100000000) > (int)((*stack)[0])) && !(direction & 0xFFFFFFFF00000000))
			cmd(&stacks->stack_a, &stacks->stack_b, arr, 1);
		cmd(&stacks->stack_a, &stacks->stack_b, op, 1);
		// print_stacks(stacks);
		// 1 ve 2. kontrolu
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
	// p("%d\n", len);
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
	// cmd(&stacks->stack_a, &stacks->stack_b, op, 1);
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
int	get_closest(t_link stack, int pivot, int mod)
{
	int	ct2;
	int	ct;
	int	len;

	len = lp_len(stack);
	ct = 0;
	ct2 = 0;
	while (stack)
	{
		if (mod)
		{
			if (pivot > (int)stack[0])
			{
				ct2 = 1;
				break ;
			}
		}
		else
		{
			if (pivot <= (int)stack[0])
			{
				ct2 = 1;
				break ;
			}
		}
		stack = stack[1];
		ct++;
	}
	if (!ct2)
		return (-1);
	stack = lp_end(stack);
	ct2 = len;
	while (stack)
	{
		if (mod)
		{
			if (pivot > (int)stack[0])
				break ;
		}
		else
		{
			if (pivot <= (int)stack[0])
				break ;
		}
		stack = stack[2];
		ct2++;
	}
	if (ct < (ct2 % len))
		return (ct);
	else
		return (ct2);
	return (-1);
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
		// print_stacks(stacks);
		// p("%d %d\n", gap[0], gap[1]); // -----------------
		if (!gap[0] || !gap[1])
		{
			; // full backward rra
			// print_stacks(stacks);
			gap[0] = get_closest(*stack, pivot[0], pivot[1]);
			if (gap[0] == -1)
				break ;
			go(((gap[0] % lp_len(*stack)) + (gap[0] >= lp_len(*stack))) | ((long)pivot[0]) * (long)0x100000000, (gap[0] >= lp_len(*stack)), (c & 127), stacks);
		}
		else if (gap[0] > gap[1])
		{
			if (gap[1] < len - gap[0])
				go(gap[1] | ((long)pivot[0]) * (long)0x100000000, 0, (c & 127), stacks); // ra
			else
				go((len - gap[0]) | ((long)pivot[0]) * (long)0x100000000, 1, (c & 127), stacks); // rra
		}
		else if (gap[0] <= gap[1])
		{
			if (gap[0] < len - gap[1])
				go(gap[0] | ((long)pivot[0]) * (long)0x100000000, 0, (c & 127), stacks); // ra
			else
				go((len - gap[1]) | ((long)pivot[0]) * (long)0x100000000, 1, (c & 127), stacks); // rra
		}

		// cmd(&stacks->stack_a, &stacks->stack_b, "ra\n", 1);
		// print_stacks(stacks);
		if (pivot[0] >= (int)((*stack)[0]))
			cmd(&stacks->stack_a, &stacks->stack_b, arr, 1);
		// print_stacks(stacks);
	}
	return (1);
}

int	find_biggest(t_link stack)
{
	int	ret;
	int	ct;

	ret = 0;
	ct = 0;
	while (stack)
	{
		if ((int)stack[0] > ret)
			ret = (int)stack[0];
		stack = stack[1];
		ct++;
	}
	return (ret);
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

int	find_index_of_biggest(t_link stack)
{
	int	ret;
	int	ct;

	ret = 0;
	ct = 0;
	while (stack)
	{
		if ((int)stack[0] > ret)
			ret = ct;
		stack = stack[1];
		ct++;
	}
	return (ret);
}

int	index_of_between(t_link stack, int val)
{
	int	ct;
	int	next;
	int	prev;
	int	smallest;
	int	biggest;

	ct = 0;
	biggest = find_biggest(stack);
	smallest = find_smallest(stack);
	if (val < smallest)
		smallest = val;
	while (lp_nod(stack, ct))
	{
		if (lp_nod(stack, ct - 1))
			prev = (int)(size_t)(lp_nod(stack, ct - 1)[0]);
		else
			(prev = (int)(lp_end(stack)[0]));
		if (lp_nod(stack, ct))
			next = (int)(size_t)(lp_nod(stack, ct)[0]);
		else
			(next = (int)(stack[0]));
		if((prev < val && next > val) || (prev == biggest && val == smallest) || (prev < val && next == smallest))
			return (ct);
		ct++;
	}
	return (ct);
}

int	distance_from_middle(int val, int len)
{
	if (val > len / 2 && len > 1)
		return (len - val);
	else
		return (val);
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

int	find_index_of_smallest(t_link stack)
{
	int	ret;
	int	small;
	int	ct;

	small = (int)stack[0];
	ret = 0;
	ct = 0;
	while (stack)
	{
		if (small > (int)stack[0])
		{
			small = (int)stack[0];
			ret = ct;
		}
		stack = stack[1];
		ct++;
	}
	return (ret);
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
		// exit(0);
		// print_stacks(&stacks);
	}
	// exit(0);
	if (lp_len(stacks.stack_a) == 3)
		triple_sort(&stacks);
	else if (lp_len(stacks.stack_a) == 2)
	{
		if ((int)(size_t)(lp_nod(stacks.stack_a, 0)[0]) > (int)(size_t)(lp_nod(stacks.stack_a, 1)[0]))
			cmd(&stacks.stack_a, &stacks.stack_b, "sa\n", 1);
	}
	// go stack_a
	while (lp_len(stacks.stack_b))
	{
		// getchar();
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
		// print_stacks(&stacks);
	}
	abs = find_index_of_smallest(stacks.stack_a);
	go(distance_from_middle(abs, lp_len(stacks.stack_a)), (abs > lp_len(stacks.stack_a) / 2), 'a', &stacks);
	exit(0);
	op = 0;
	// cmd(&stacks.stack_a, &stacks.stack_b, "rra\n", 1);
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

	// p("sss%dss", atoi("-+1"));
	(void)av;
	(void)ac;
	stacks.stack_a = NULL;
	stacks.stack_b = NULL;
	// av2 = file_load("./aww");
	// load_nums(tablen(av2), av2, &stacks);
	load_nums(ac, av, &stacks);
	// lp_iter(stacks.stack_a, 0, iter_stack_func, &stacks.stack_b);
	start_sort(stacks, ac);
	while (stacks.stack_a)
        lp_pop(&stacks.stack_a, del);
	while (stacks.stack_b)
        lp_pop(&stacks.stack_b, del);
	return (0);
}
