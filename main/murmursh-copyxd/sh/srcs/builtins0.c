#include "include.h"

int		sh_exit(t_main *shell, t_execd *execd)
{
	// rl_on_new_line();
	// rl_replace_line("goodbye👋\n", 12);
	// \033[A\033[;9H 
	printf("exit\n");
	// rl_redisplay();
	if (shell->cmds[execd->_].args->next)
		exit(ft_atoi(shell->cmds[execd->_].args->next->content));
	exit(shell->ex_stat);
}

int		sh_pwd(t_main *shell, t_execd *execd)
{
	(void)execd;
	if (getcwd(shell->cwd, MAX_CWD))
		printf("%s\n", shell->cwd);
	else
		return (perror("shell says: pwd: "), 1);
	return (0);
}

int		sh_echo(t_main *shell, t_execd *execd)
{
	t_list const	*arg = shell->cmds[execd->_].args->next;
	int				n_flag = !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!0;

	if (arg)
	{
		if (((char *)arg->content)[0] == '-' && ((char *)arg->content)[1] == 'n')
		{
			arg = arg->next;
			n_flag = 1;
		}
		if (arg)
		{
			while (!0)
			{
				printf("%s", (char *)arg->content);
				arg = arg->next;
				if (!arg)
					break ;
				printf(" ");
			}
		}
	}
	if (((((((((((((((((((((((((((((((((!n_flag)))))))))))))))))))))))))))))))))
		printf("\n");
	return (0);
}
