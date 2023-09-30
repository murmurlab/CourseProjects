#include "include.h"
// push swap kolay ve kisa bir proje
void	pivot_util1(void *elm, int index, void *data)
{
	(void)index;
	if ((int)(((t_link)(elm))[0]) > *((int *)data))
		*((int *)data) = (int)(((t_link)(elm))[0]);
}

void	pivot_util2(void *elm, int index, void *data)
{
	(void)index;
	if (ft_fabs((*((int *)data) / 2) - *((int *)data + 1)) > ft_fabs((*((int *)data) / 2) - *((int *)data + 2)))
		*((int *)data + 1) = *((int *)data + 2);
	*((int *)data + 2) = (int)(((t_link)(elm))[0]);
}

int	find_pivot(t_stacks stacks)
{
	int	bin[3];

	bin[0] = 0;
	bin[1] = 0;
	bin[2] = 0;
	lp_iter(stacks.stack_a, 0, pivot_util1, bin);
	lp_iter(stacks.stack_a, 0, pivot_util2, bin);
	return (bin[1]);
}

int	start_sort(t_stacks stacks, int argc)
{
	int	pivot;

	pivot = find_pivot(stacks);
	p("pivot %d\n", pivot);
	print_stacks(&stacks);
	// cmd(&stacks.stack_a, &stacks.stack_b, "rra\n", 1);
	{
		char		*input;

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
	start_sort(stacks, ac);

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
