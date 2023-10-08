#include "include.h"
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

int	*biggest_gap(int *zone, int pivot, t_link stack, int len)
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
		if ((int)(size_t)(lp_nod(stack, zone[0])[0]) <= pivot || zone[0] == stock_zone)
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

void go(int len, int direction, char stack, t_stacks *stacks)
{
	char	*op;

	if (direction)
	{
		if (stack == 'a')
			op = strcln("rra");
		else if (stack == 'b')
			op = strcln("rrb");
	}
	else
	{
		if (stack == 'a')
			op = strcln("ra");
		else if (stack == 'b')
			op = strcln("rb");
	}
	while (len--)
		cmd(&stacks->stack_a, &stacks->stack_b, op, 1);
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
			if (pivot < (int)stack[0])
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

int	go_path(int pivot, t_stacks *stacks, int len, int c)
{
	int		ct;
	int		*gap;
	t_link	stack;

	ct = 0;
	if ((c & 127) == 'a')
		stack = stacks->stack_a;
	if ((c & 127) == 'b')
		stack = stacks->stack_b;
	while (ct != len / 2)
	{
		gap = biggest_gap((int [2]){0, 0}, pivot, stack, len);
		p("%d %d\n", gap[0], gap[1]);
		if (!gap[0] || !gap[1])
		{
			; // full backward rra
			gap[0] = get_closest(stack, pivot, (c & 128));
			go(gap[0] % len, (gap[0] >= len), (c & 127), stacks);
		}
		else if (gap[0] > gap[1])
		{
			if (gap[1] < len - gap[0])
				go(gap[1], 0, (c & 127), stacks); // ra
			else
				go(len - gap[0], 1, (c & 127), stacks); // rra
		}
		else if (gap[0] <= gap[1])
		{
			if (gap[0] < len - gap[1])
				go(gap[0], 0, (c & 127), stacks); // ra
			else
				go(len - gap[1], 1, (c & 127), stacks); // rra
		}
		print_stacks(stacks);
		cmd(&stacks->stack_a, &stacks->stack_b, "pb\n", 0);
		ct++;
	}
	return (1);
}

int	start_sort(t_stacks stacks, int argc)
{
	int	a_b[2];
	int	pivot;
	int	*res;
	int	op;

	op = 0;
	a_b[0] = 0;
	a_b[1] = 0;
	pivot = find_pivot(stacks.stack_a);
	res = biggest_gap(a_b, pivot, stacks.stack_a, argc - 2);
	// p("len: %d\n", argc);
	p("big gap: %d, %d\n", res[0], res[1]);
	p("pivot %d\n", pivot);
	print_stacks(&stacks);
	go_path(pivot, &stacks, argc - 1, 'a' | BIGGER_THAN_PIVOT);
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
			{
				// usleep(3000000);
				// system("clear");
				p("operations: %d\n", op);
				print_stacks(&stacks);
			}
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
	// char		**av2;

	// p("sss%dss", atoi("-+1"));
	(void)av;
	(void)ac;
	stacks.stack_a = NULL;
	stacks.stack_b = NULL;
	// av2 = file_load("./aww");
	// load_nums(tablen(av2), av2, &stacks);
	load_nums(ac, av, &stacks);
	// lp_iter(stacks.stack_a, 0, iter_stack_func, &stacks.stack_b);

	// lp_pop(&stacks.stack_b, del);
	// lp_pop(&stacks.stack_b, del);
	// lp_pop(&stacks.stack_b, del);
	// lp_pop(&stacks.stack_b, del);
	// lp_pop(&stacks.stack_b, del);
	// lp_pop(&stacks.stack_b, del);
	// lp_pop(&stacks.stack_b, del);
	// p("rra\n");
	// p("sa\n");
	// print_links(stacks.stack_a, stacks.stack_b);
	start_sort(stacks, ac);

	// print_stacks(&stacks);
	// cmd(&stacks.stack_a, &stacks.stack_b, "rr");
	// tmp = lp_nod(stacks.stack_a, 1);
	// lp_swap(lp_nod(stacks.stack_a, 0), lp_nod(stacks.stack_a, 1));
	// stacks.stack_a = tmp;
	// print_stacks(&stacks);
	// print_links(stacks.stack_a, stacks.stack_b);
	while (stacks.stack_a)
        lp_pop(&stacks.stack_a, del);
	while (stacks.stack_b)
        lp_pop(&stacks.stack_b, del);
	return (0);
}
