#include "include.h"

// push swap kolay ve kisa bir proje
// int		print_stacks(t_stacks *stacks);// del
// char    **file_load(char *path);
// int     tablen(char **tab);
// void	print_links(void *iter, void *data);
void	pivot_util(void *elm, int index, void *data)
{
	static int	big;
	static int	tmp;

	(void)index;
	if ((int)(((t_link)(elm))[0]) > big)
		big = (int)(((t_link)(elm))[0]);
	if (ft_fabs((big / 2) - *((int *)data)) > ft_fabs((big / 2) - tmp))
		*((int *)data) = tmp;
	tmp = (int)(((t_link)(elm))[0]);
}

int	find_pivot(t_stacks stacks)
{
	int	pivot;

	pivot = 0;
	lp_iter(stacks.stack_a, 0, pivot_util, &pivot);
	return (pivot);
}

int	start_sort(t_stacks stacks)
{
	int	pivot;
	pivot = find_pivot(stacks);
	p("pivot %d\n", pivot);
	print_stacks(&stacks);
	cmd(&stacks.stack_a, &stacks.stack_b, "rra\n", 1);
	print_stacks(&stacks);
	cmd(&stacks.stack_a, &stacks.stack_b, "sa\n", 1);
	print_stacks(&stacks);
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
	start_sort(stacks);

	// print_stacks(&stacks);
	// print_links(stacks.stack_a, stacks.stack_b);
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
