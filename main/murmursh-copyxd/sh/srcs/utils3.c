/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:15:55 by ahbasara          #+#    #+#             */
/*   Updated: 2024/01/29 16:15:56 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	clear_cmds(t_cmd *cmds, size_t cmd_ct)
{
	size_t		_;

	_ = 0;
	if (!cmds)
		return ;
	while (_ < cmd_ct)
	{
		free(cmds[_].cmd);
		ft_lstclear(&cmds[_].args, del);
		_++;
	}
}

void	clear_pipes(int **pipes, size_t cmd_ct)
{
	size_t		_;

	_ = 0;
	while ((_ + 1) < cmd_ct)
		free(pipes[_++]);
	free(pipes);
}

void	f2(t_list *node)
{
	free(node);
}

void	ex(t_main *shell)
{
	(void)shell;
}

int	none(t_main *shell, char *string, int oflag)
{
	(void)shell;
	(void)string;
	(void)oflag;
	return (0);
}