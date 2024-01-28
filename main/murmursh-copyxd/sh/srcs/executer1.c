/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:46:08 by ahbasara          #+#    #+#             */
/*   Updated: 2024/01/28 18:48:22 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
}

		/**
		 * must valid last given in/out-prompt (<, >, >>, <<);
		 * 
		 */

void	child(t_main *shell, t_execd *execd)
{
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

int	launch_program(t_main *shell, t_execd *execd)
{
	int			err;
	char *const	*lstarr = lsttoarr(shell->cmds[execd->_].args);

	list2env(shell);
	err = execve(shell->cmds[execd->_].cmd, lstarr, shell->env);
	ft_lstclear(&shell->cmds[execd->_].args, del);
	perror(SHELLSAY EXEC_ERR);
	free_tab((char **)lstarr);
	return (err);
}
