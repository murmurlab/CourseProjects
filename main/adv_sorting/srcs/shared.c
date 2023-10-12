#include "include.h"

void	load_nums(int ac, char **av, t_stacks *stacks)
{
	long	num;
	t_link	tmp;
	int		sorted;

	sorted = 0;
	if (ac-- < 3)
		(write(2, "enter at least 2 number\n", 24), exit(1));
	while (ac)
	{
		num = x_atoi(av[ac]);
		if (num == 0 && av[ac][0] != '0')
			exit((write(2, "Error:\nnot integer.\n", 20), 1));
		if (num > INT32_MAX || num < INT32_MIN)
			exit((write(2, "Error:\nout of int range.\n", 25), 1));
		else if (lp_filter(stacks->stack_a, dup_cntl, (void *)num))
			exit((write(2, "Error:\nduplicate number.\n", 26), 1));
		else
		{
			if (stacks->stack_a && num > (int)((stacks->stack_a)[0]) && !sorted)
				sorted = 99999;
			if (ac == 1 && !sorted)
				(write(2, "already sorted\n", 15), exit(1));
			tmp = lp_new((void *)num);
			lp_push(&stacks->stack_a, tmp);
		}
		ac--;
	}
}

int	check_sort(t_link stack, int i)
{
	i -= 2;
	while (i > 0)
	{
		if (lp_nod(stack, i)[0] < lp_nod(stack, i - 1)[0])
			return (i);
		i--;
	}
	return (0);
}
