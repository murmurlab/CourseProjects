#include "include.h"

int	main(int argc, char *argv[])
{
	t_stacks	stacks;
	char		*input;
	int			i;
	int			tmp;

	i = 0;
	stacks.stack_a = NULL;
	stacks.stack_b = NULL;
	load_nums(argc, argv, &stacks);
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
