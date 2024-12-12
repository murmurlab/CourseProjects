/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:21:43 by ahbasara          #+#    #+#             */
/*   Updated: 2024/01/30 09:04:36 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	change_io(t_main *shell, t_execd *execd, int *stock_fd)
{
	if (shell->cmds[execd->_].out)
	{
		stock_fd[0] = dup(STDOUT_FILENO);
		dup2(shell->cmds[execd->_].out, STDOUT_FILENO);
	}
	if (shell->cmds[execd->_].in)
	{
		stock_fd[1] = dup(STDIN_FILENO);
		dup2(shell->cmds[execd->_].in, STDIN_FILENO);
	}
}

void	restore_io(t_main *shell, t_execd *execd, int *stock_fd)
{
	if (shell->cmds[execd->_].out)
	{
		close(shell->cmds[execd->_].out);
		dup2(stock_fd[0], STDOUT_FILENO);
	}
	if (shell->cmds[execd->_].in)
	{
		close(shell->cmds[execd->_].in);
		dup2(stock_fd[1], STDIN_FILENO);
	}
}

void	open_pipes(t_main *shell, t_execd *execd)
{
	size_t		_;

	_ = 0;
	execd->fd = NULL;
	if (shell->cmd_ct - 1)
		execd->fd = malloc((sizeof(int *) * (shell->cmd_ct - 1)));
	while (_ < shell->cmd_ct - 1)
	{
		execd->fd[_] = malloc(sizeof(int [2]));
		pipe(execd->fd[_++]);
	}
}

void	multi_exe(t_main *shell, t_execd *execd)
{
	g_qsignal = 1;
	while (execd->_ < shell->cmd_ct)
	{
		execd->pids[execd->_] = fork();
		if (execd->pids[execd->_] == 0)
			child(shell, execd);
		execd->_++;
	}
	--execd->_;
	close_all_pipes_for_main(shell, execd);
	wait_all(shell, execd);
}

void	exe_cute_cat(t_main *shell)
{
	t_execd		execd;
	char		*tmp;

	open_pipes(shell, &execd);
	execd.pids = malloc(sizeof(pid_t) * shell->cmd_ct);
	execd._ = 0;
	execd.pids[execd._] = 1;
	if ((shell->cmd_ct == 1) && shell->cmds[0].builtin_offset)
		single_exe(shell, &execd);
	else
		multi_exe(shell, &execd);
	tmp = ft_itoa(shell->ex_stat);
	set(shell, ft_strsjoin((t_merge *[]){\
	&(t_merge){"?", 1}, &(t_merge){"=", 1},
			&(t_merge){tmp, ft_strlen(tmp)}, NULL}));
	free(tmp);
	reset(shell, &execd);
}
