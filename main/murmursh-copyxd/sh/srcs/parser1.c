/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 20:31:24 by ahbasara          #+#    #+#             */
/*   Updated: 2024/01/28 20:32:12 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	set_heredoc(t_main *shell, char *string, int oflag)
{
	int	fd[2];

	(void)oflag;
	pipe(fd);
	if (fd[0] < 0 || fd[1] < 0)
		return (err(errno, string), free(string),
			shell->cmds[shell->current].io_err = 1,
			shell->cmds[shell->current].ex = 1,
			-1);
	prompt_heredoc(string, fd);
	if (shell->cmds[shell->current].in > 2)
		close(shell->cmds[shell->current].in);
	shell->cmds[shell->current].in = fd[0];
	shell->to_be = shell->has_cmd;
	return (free(string), 0);
}

int	set_in(t_main *shell, char *string, int oflag)
{
	int	fd;

	if (shell->cmds[shell->current].io_err)
		return (free(string), shell->cmds[shell->current].io_err = 1, -1);
	fd = open(string, oflag, 0644);
	if (fd < 0)
		return (err(errno, string), free(string),
			shell->cmds[shell->current].io_err = 1,
			shell->cmds[shell->current].ex = 1,
			-1);
	if (shell->cmds[shell->current].in > 2)
		close(shell->cmds[shell->current].in);
	shell->cmds[shell->current].in = fd;
	shell->to_be = shell->has_cmd;
	return (free(string), 0);
}

int	set_out(t_main *shell, char *string, int oflag)
{
	int	fd;

	if (shell->cmds[shell->current].io_err)
		return (free(string), shell->cmds[shell->current].io_err = 1, -1);
	fd = open(string, oflag, 0644);
	if (fd < 0)
		return (err(errno, string), free(string),
			shell->cmds[shell->current].io_err = 1,
			shell->cmds[shell->current].ex = 1,
			-1);
	if (shell->cmds[shell->current].out > 2)
		close(shell->cmds[shell->current].out);
	shell->cmds[shell->current].out = fd;
	shell->to_be = shell->has_cmd;
	return (free(string), 0);
}

int	set_cmd(t_main *shell, char *string, int oflag)
{
	(void)oflag;
	shell->cmds[shell->current].cmd = string;
	ft_lstadd_back(&shell->cmds[shell->current].args,
		ft_lstnew(ft_strdup(string)));
	shell->to_be = 1;
	shell->has_cmd = 1;
	return (0);
}

int	set_arg(t_main *shell, char *string, int oflag)
{
	(void)oflag;
	ft_lstadd_back(&shell->cmds[shell->current].args, ft_lstnew(string));
	return (0);
}
