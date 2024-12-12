/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:48:29 by ahbasara          #+#    #+#             */
/*   Updated: 2024/01/30 09:02:57 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	close_pipes(t_main *data, t_execd *execd)
{
	size_t													_;

	_ = 1;
	if (execd->_ != 0)
		close(execd->fd[0][1]);
	else if ((execd->_ != (data->cmd_ct - 1)) && (data->cmd_ct != 1))
		close(execd->fd[data->cmd_ct - 2][0]);
	if (execd->_ == 0 && data->cmd_ct != 1 && data->cmd_ct != 2)
	{
		close(execd->fd[_ - 1][0]);
		close(execd->fd[_][1]);
	}
	while (_ < execd->_)
	{
		close(execd->fd[_ - 1][0]);
		close(execd->fd[_][1]);
		_++;
	}
	_++;
	while (_ < data->cmd_ct - 1)
	{
		close(execd->fd[_ - 1][0]);
		close(execd->fd[_][1]);
		_++;
	}
}

void	single_exe(t_main *shell, t_execd *execd)
{
	int			stock_fd[2];

	if (!shell->cmds[0].io_err)
	{
		change_io(shell, execd, stock_fd);
		shell->ex_stat = \
		shell->coms[shell->cmds[0].builtin_offset].func(shell, execd);
		restore_io(shell, execd, stock_fd);
	}
	else
		shell->ex_stat = shell->cmds[0].io_err;
}
