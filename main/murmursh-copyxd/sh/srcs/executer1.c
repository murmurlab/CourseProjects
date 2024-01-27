#include "include.h"

void	close_all_pipes_for_main(t_main *shell, t_execd *execd)
{
	size_t		_;

	_ = 0;
	while (_ < shell->cmd_ct - 1)
	{
		close(execd->fd[_][0]);
		close(execd->fd[_++][1]);
	}
}

void	set_io(t_main *shell, t_execd *execd)
{
	if (!shell->cmds[execd->_].in)
	{
		if (execd->_ != 0)
			dup2(execd->fd[execd->_ - 1][0], STDIN_FILENO);
	}
	else
	{
		if (execd->_ != 0)
			close(execd->fd[execd->_ - 1][0]);
		dup2(shell->cmds[execd->_].in, STDIN_FILENO);
	}
	if (!shell->cmds[execd->_].out)
	{
		if ((execd->_ != (shell->cmd_ct - 1)) && (shell->cmd_ct != 1))
			dup2(execd->fd[execd->_][1], STDOUT_FILENO);	
	}
	else
	{
		if ((execd->_ != (shell->cmd_ct - 1)) && (shell->cmd_ct != 1))
			close(execd->fd[execd->_][1]);
		dup2(shell->cmds[execd->_].out, STDOUT_FILENO);
	}
	close_pipes(shell, execd);
	// dprintf(2, "> setted io\n");
}

void	event_sigpipe(int signum)
{
	printf("dul dul dulduldul dul dul\n");
	(void)signum;
	exit(0);
}

void	child(t_main *shell, t_execd *execd)
{
	// dup2(1, shell->cmds[execd->_].out);
	// dup2(0, shell->cmds[execd->_].in);
	/**
	 * must valid last given in/out-prompt (<, >, >>, <<);
	 * 
	 */
	set_io(shell, execd);
	if (shell->cmds[execd->_].cmd && !shell->cmds[execd->_].io_err)
	{
		signal(SIGPIPE, event_sigpipe);
		exit(shell->coms[(shell->cmds[execd->_].builtin_offset)] \
			.func(shell, execd));
	}
	exit(shell->cmds[execd->_].ex);
}

void	wait_all(t_main *shell, t_execd *execd)
{
	size_t		_;

	_ = shell->cmd_ct - 2;
	while ((size_t)-1 > _)
		wait4(execd->pids[_--], NULL, 0, NULL);
	wait4(execd->pids[shell->cmd_ct - 1], &shell->ex_stat, 0, NULL);
	g_qsignal = 0;
	shell->ex_stat = WEXITSTATUS(shell->ex_stat);
}

int		launch_program(t_main *shell, t_execd * execd)
{
	int		err;
	char	**lstarr = lsttoarr(shell->cmds[execd->_].args);

	list2env(shell);
	// printf("var %s\n", shell->env[0]);
	// printf("executing cmd: %s, \n", shell->cmds[execd->_].cmd);
	err = execve(shell->cmds[execd->_].cmd, lstarr, shell->env);
	ft_lstclear(&shell->cmds[execd->_].args, del);
	perror(SHELLSAY"exec error");
	// printf("cant executing\n");
	// free_tab(lstarr);
	// if (shell->cmds[execd->_].args)
	// 	printf("command not found: %s\n", "a");
	return (err);
}
