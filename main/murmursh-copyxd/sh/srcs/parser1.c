#include "include.h"

int		set_heredoc(t_main *shell, char *string, int oflag)
{
	int fd[2];

	(void)oflag;
	pipe(fd);
	if (fd[0] < 0 || fd[1] < 0)
		return (err(errno, string), free(string), -1);
	prompt_heredoc(string, fd);
	shell->cmds[shell->current].in = fd[0];
	shell->to_be = shell->has_cmd;
	return (free(string), 0);
}

int		set_in(t_main *shell, char *string, int oflag)
{

	const int fd = open(string, oflag, 0644);

	if (fd < 0)
		return (err(errno, string), free(string), -1);
	shell->cmds[shell->current].in = fd;
	shell->to_be = shell->has_cmd;
	return (free(string), 0);
}

int		set_out(t_main *shell, char *string, int oflag)
{
	const int fd = open(string, oflag, 0644);

	if (fd < 0)
		return (err(errno, string), free(string), -1);
	shell->cmds[shell->current].out = fd;
	shell->to_be = shell->has_cmd;
	return (free(string), 0);
}

int		set_cmd(t_main *shell, char *string, int oflag)
{
	// printf("> set cmd\n");
	(void)oflag;
	shell->cmds[shell->current].cmd = string;
	ft_lstadd_back(&shell->cmds[shell->current].args, ft_lstnew(ft_strdup(string)));
	// printf("> set arg 0 on setting cmd: %s\n", shell->cmds[shell->current].args->content);
	shell->to_be = 1;
	shell->has_cmd = 1;
	return (0);
}

int		set_arg(t_main *shell, char *string, int oflag)
{
	// printf("> new arg %s\n", string);
	(void)oflag;
	ft_lstadd_back(&shell->cmds[shell->current].args, ft_lstnew(string));
	return (0);
}
