#include "include.h"
#include "fcntl.h"
// push swap kolay ve kisa bir proje

void	prepare(t_sort *sort)
{
	while (1)
	{
		if (lp_len(sort->stacks->stack_a) < 4)
			break ;
		sort->pvt[0] = find_pivot(sort->stacks->stack_a);
		sort->pvt[1] = 1;
		go_path(sort, lp_len(sort->stacks->stack_a), 'a');
	}
	if (lp_len(sort->stacks->stack_a) == 3)
		triple_sort(sort->stacks);
	else if (lp_len(sort->stacks->stack_a) == 2)
	{
		if ((int)(size_t)(lp_nod(sort->stacks->stack_a, 0)[0]) >
			(int)(size_t)(lp_nod(sort->stacks->stack_a, 1)[0]))
			cmd(&sort->stacks->stack_a, &sort->stacks->stack_b, "sa\n", 1);
	}
}

void	flush_ops(t_sort *sort)
{
	if ((sort->op & 0b00000001) == 0b00000001)
		cmd(&sort->stacks->stack_a, &sort->stacks->stack_b, "ra\n", 1);
	if ((sort->op & 0b00000010) == 0b00000010)
		cmd(&sort->stacks->stack_a, &sort->stacks->stack_b, "rb\n", 1);
	if ((sort->op & 0b00000100) == 0b00000100)
		cmd(&sort->stacks->stack_a, &sort->stacks->stack_b, "rra\n", 1);
	if ((sort->op & 0b00001000) == 0b00001000)
		cmd(&sort->stacks->stack_a, &sort->stacks->stack_b, "rrb\n", 1);
}

void	zort(t_sort *sort)
{
	int		fun;

	while (lp_len(sort->stacks->stack_b))
	{
		sort->abs = between(sort->stacks->stack_a,
				(int)(lp_nod(sort->stacks->stack_b, cost(sort->stacks))[0]));
		sort->abs_b = cost(sort->stacks);
		sort->a_b[0] = midlen(sort->abs, lp_len(sort->stacks->stack_a));
		sort->a_b[1] = midlen(sort->abs_b, lp_len(sort->stacks->stack_b));
		sort->a_b[2] = 0;
		while (1)
		{
			sort->pvt[0] = 0;
			sort->pvt[1] = 0;
			fun = run_ops(sort);
			if (fun == 1)
				break ;
			else if (fun == 2)
				continue ;
			flush_ops(sort);
		}
		cmd(&sort->stacks->stack_a, &sort->stacks->stack_b, "pa\n", 1);
	}
}

int	start_sort(t_stacks *stacks, int argc)
{
	t_sort	sort;

	sort.stacks = stacks;
	sort.a_b[0] = 0;
	sort.a_b[1] = 0;

	prepare(&sort);
	zort(&sort);
	sort.abs = find_index_of_smallest(sort.stacks->stack_a);
	go(midlen(sort.abs, lp_len(sort.stacks->stack_a)), (sort.abs > \
		lp_len(sort.stacks->stack_a) / 2) | 0x0000000100000000, 'a',
		sort.stacks);
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
	load_nums(ac, av, &stacks, 1);
	start_sort(&stacks, ac);
	print_stacks(&stacks);
	free_stack(&stacks);
	return (0);
}

// void	__attribute__((destructor))after_main()
// {
// 	pause();
// }
