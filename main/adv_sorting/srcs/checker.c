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














int main(int argc, char *argv[])
{
	t_stacks	stacks;
	char		*input;
	int			i;
    int         tmp;

	i = 0;
	stacks.stack_a = NULL;
	stacks.stack_b = NULL;
	
	load_nums(argc, argv, &stacks);

	char		**av2;
	while (42)
	{
		input = multi_get_line(0);
		if (input && xstrncmp(input, "ext\n", 4))
			cmd(&stacks.stack_a, &stacks.stack_b, input, 0);
		else
			break ;
		i++;
	}
    tmp = check_sort(stacks.stack_a, argc);
	if (!tmp)
	{
		p("[OK!]\n");
		p("Number of commands: %d\n", i);
	}
	else
		p("[KO!] %d\n", tmp);
    return (0);
}
