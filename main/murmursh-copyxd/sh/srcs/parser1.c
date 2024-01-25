#include "include.h"

void	set_heredoc(t_main *shell, char *string, int oflag)
{
	int fd[2];

	pipe(fd);
	if (fd[0] < 0 || fd[1] < 0)
		return ;
	prompt_heredoc(shell, string, fd);
	free(string);
	shell->cmds[shell->current].in = fd[0];
	shell->to_be = shell->has_cmd;
}

void	set_in(t_main *shell, char *string, int oflag)
{

	const int fd = open(string, oflag, 0644);

	free(string);
	if (fd < 0)
		return ;
	shell->cmds[shell->current].in = fd;
	shell->to_be = shell->has_cmd;
}

void	set_out(t_main *shell, char *string, int oflag)
{
	const int fd = open(string, oflag, 0644);

	free(string);
	if (fd < 0)
		return ;
	shell->cmds[shell->current].out = fd;
	shell->to_be = shell->has_cmd;
}

void	set_cmd(t_main *shell, char *string, int oflag)
{
	// printf("> set cmd\n");
	(void)oflag;
	shell->cmds[shell->current].cmd = string;
	ft_lstadd_back(&shell->cmds[shell->current].args, ft_lstnew(ft_strdup(string)));
	// printf("> set arg 0 on setting cmd: %s\n", shell->cmds[shell->current].args->content);
	shell->to_be = 1;
	shell->has_cmd = 1;
}

void	set_arg(t_main *shell, char *string, int oflag)
{
	// printf("> new arg %s\n", string);
	(void)oflag;
	ft_lstadd_back(&shell->cmds[shell->current].args, ft_lstnew(string));
}
