#include "include.h"

int	main(int argc, char *argv[])
{
	t_stacks	stacks;
	char		*input;
	int			i;

	i = 0;
	stacks.stack_a = NULL;
	stacks.stack_b = NULL;
	load_nums(argc, argv, &stacks, 0);
	while (42)
	{
		input = multi_get_line(0);
		if (input && xstrncmp(input, "ext\n", 4))
			cmd(&stacks.stack_a, &stacks.stack_b, input, 0);
		else
			break ;
		i++;
	}
	if (!check_sort(stacks.stack_a, lp_len(stacks.stack_a) + 1))
		p("OK\n");
	else
		write(2, "KO\n", 3);
	return (0);
}
