#include "include.h"

void	load_nums_ok(int ac, char **av, t_stacks *stacks, int sort_cntl)
{
	long	num;
	t_link	tmp;
	int		sorted;

	sorted = 0;
	while (ac)
	{
		num = x_atoi(av[ac]);
		if (num == 0 && av[ac][0] != '0')
			exit((write(2, "Error\n", 7), free_stack(stacks), 1));
		if (num > INT32_MAX || num < INT32_MIN)
			exit((write(2, "Error\n", 7), free_stack(stacks), 1));
		else if (lp_filter(stacks->stack_a, dup_cntl, (void *)num))
			exit((write(2, "Error\n", 7), free_stack(stacks), 1));
		else
		{
			if (stacks->stack_a && num > (int)((stacks->stack_a)[0]) && !sorted)
				sorted = 99999;
			if (ac == 1 && !sorted && sort_cntl)
				exit((free_stack(stacks), 1));
			tmp = lp_new((void *)num);
			lp_push(&stacks->stack_a, tmp);
		}
		ac--;
	}
}

void	load_nums(int ac, char **av, t_stacks *stacks, int sort_cntl)
{
	long	num;
	int		sorted;

	sorted = 0;
	if (ac-- < 3)
	{
		while (ac)
		{
			num = x_atoi(av[ac]);
			if (num == 0 && av[ac][0] != '0')
				exit((write(2, "Error\n", 7), 1));
			if (num > INT32_MAX || num < INT32_MIN)
				exit((write(2, "Error\n", 7), 1));
			ac--;
		}
		exit(1);
	}
	load_nums_ok(ac, av, stacks, sort_cntl);
}

int	check_sort(t_link stack, int i)
{
	i -= 2;
	while (i > 0)
	{
		if ((int)lp_nod(stack, i)[0] < (int)lp_nod(stack, i - 1)[0])
			return (i);
		i--;
	}
	return (0);
}

void	free_stack(t_stacks *stacks)
{
	while (stacks->stack_a)
		lp_pop(&stacks->stack_a, del);
	while (stacks->stack_b)
		lp_pop(&stacks->stack_b, del);
}