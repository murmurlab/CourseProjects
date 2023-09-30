#include "include.h"

int main(int argc, char *argv[])
{
	t_stacks	stacks;
	char		*input;

	stacks.stack_a = NULL;
	stacks.stack_b = NULL;
	load_nums(argc, argv, &stacks);
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
			print_stacks(&stacks);
		}
	}
	if (!check_sort(stacks.stack_a, argc))
		p("[OK!]\n");
	else
		p("[KO!]\n");
    return (0);
}
