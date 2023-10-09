#include "include.h"










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
    if (ret)
        p("Error:\ncommand was not executed %d\n", ret);
    return (ret);
}






// 79 80 94 67 35 95 45 89 44 74 52 57 34 49 72 2 84 87 68 55 97 59 83 40 11 53 6 70 27 100 4 9 90 5 28 36 66 33 22 51 14 81 42 18 73 48 82 65 96 77 86 47 32 50 19 29 39 3 54 16 88 20 64 10 69 78 7 38 63 75 25 21 23 13 31 92 24 85 8 61 91 93 37 56 62 1 99 98 41 43 15 12 30 76 60 46 17 26 58 71







int main(int argc, char *argv[])
{
	t_stacks	stacks;
	char		*input;
	int			i;

	i = 0;
	stacks.stack_a = NULL;
	stacks.stack_b = NULL;
	
	load_nums(argc, argv, &stacks);

	char		**av2;

	// p("sss%dss", atoi("-+1"));
	// av2 = file_load("./aww");
	// load_nums(tablen(av2), av2, &stacks);

	{
		// system("clear");
		print_stacks(&stacks);
	}
	while (42)
	{
		input = multi_get_line(0);
		if (input && xstrncmp(input, "ext\n", 4))
			cmd(&stacks.stack_a, &stacks.stack_b, input, 1);
		else
			break ;
		{
			// usleep(3000000);
			// system("clear");
			// print_stacks(&stacks);
		}
		i++;
	}
	if (!check_sort(stacks.stack_a, argc))
	{
		print_stacks(&stacks);
		p("[OK!]\n");
		p("Number of commands: %d\n", i);
	}
	else
		p("[KO!]\n");
    return (0);
}
