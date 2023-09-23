#include "include.h"
#include <time.h>
#include <stdio.h>
	// push swap kolay ve kisa bir proje
int		print_stacks(t_stacks *stacks);// del
char    **file_load(char *path);
int     tablen(char **tab);
void	print_links(void *iter, void *data);

int		dup_cntl(void *nod, void *cmp)
{
	if (((t_link)nod)[0] == cmp)
		return (1);
	return (0);
}

void	load_nums(int ac, char **av, t_stacks *stacks)
{
	long	num;
	t_link	tmp;

	ac--;
	while (ac)
	{
		num = x_atoi(av[ac]);
		if (num > INT32_MAX || num < INT32_MIN)
			exit((p("Error:\nout of int range.\n", num), 1));
		else if (lp_filter(stacks->stack_a, dup_cntl, (void *)num))
			exit((p("Error:\nduplicate number.\n", num), 1));
		else
		{
			// if (ac == 1 && sorted)
				// p("already sorted");
			// p("[OK]\n", num);
			tmp = lp_new((void *)num);
			lp_push(&stacks->stack_a, tmp);
			// sorted

		}
		ac--;
	}
	
}
void iter_stack_func(void *iter, int index, void *data)
{
	(void)iter;
	(void)index;
	(void)data;
	// p("[%d][%d]\n", (*(t_link *)data), ((t_link)iter)[0]);
	lp_push((t_link *)data, lp_new(((t_link)iter)[0]));
	
}

void     del(void **tab)
{
	(void)tab;
}

int	main(int ac, char *av[])
{
	t_stacks	stacks;
	char		**av2;

	(void)av;
	(void)ac;
	stacks.stack_a = NULL;
	stacks.stack_b = NULL;
	av2 = file_load("./aww");
	load_nums(tablen(av2), av2, &stacks);
	// load_nums(ac, av, &stacks);
	lp_iter(stacks.stack_a, 0, iter_stack_func, &stacks.stack_b);

	// lp_pop(&stacks.stack_b, del);
	// lp_pop(&stacks.stack_b, del);
	// lp_pop(&stacks.stack_b, del);
	// lp_pop(&stacks.stack_b, del);
	// lp_pop(&stacks.stack_b, del);
	// lp_pop(&stacks.stack_b, del);
	// lp_pop(&stacks.stack_b, del);

    p("\na: %d		b: %d\n", lp_len(stacks.stack_a), lp_len(stacks.stack_b));
	print_stacks(&stacks);
    p("\n		a: %d							b: %d\n", lp_len(stacks.stack_a), lp_len(stacks.stack_b));
	p("===================================================================================================\n");
	p("===================================================================================================\n");
	print_links(stacks.stack_a, stacks.stack_b);
	p("===================================================================================================\n");
	p("===================================================================================================\n");
	while (stacks.stack_a)
        lp_pop(&stacks.stack_a, del);
	while (stacks.stack_b)
        lp_pop(&stacks.stack_b, del);
	return (0);
}
