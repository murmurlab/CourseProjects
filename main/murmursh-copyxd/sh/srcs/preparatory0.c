/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparatory0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 20:32:24 by ahbasara          #+#    #+#             */
/*   Updated: 2024/01/28 20:33:21 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

char	*resolve_cmd(t_main *shell, char *string, size_t _)
{
	char		*loc;
	char		*path;

	path = (get_ref(shell, "PATH"));
	loc = check_cmd(string, path);
	if (!loc)
	{
		err(CMD_NOTFND, string);
		shell->cmds[_].ex = 127;
	}
	return (loc);
}

/**
 * replace `if (path[_] == ':' || !path[_])` to `if (path[_] == ':')`
 * 
 * move the following lines to outside the while
 * if (!path[_])
 * 		break ;
 */
char	*check_cmd(char *cmd, char *path)
{
	char		*var;
	size_t		_;
	struct stat	sb;

	if (!path)
		return (NULL);
	_ = 0;
	while ("")
	{
		if (path[_] == ':' || !path[_])
		{
			if (!path[_] && !_)
				break ;
			var = ft_strsjoin((t_merge *[]){\
					&(t_merge){path, _},
					&(t_merge){"/", 1},
					&(t_merge){cmd, ft_strlen(cmd)}, NULL
				});
			errno = 0;
			stat(var, &sb);
			if (!errno)
			{
				if (S_ISREG(sb.st_mode))
				{
					if (!access(var, X_OK))
						break ;
					else
						err(EPERM, cmd);
				}
			}
			free(var);
			var = NULL;
			if (!path[_])
				break ;
			path += _ + 1;
			_ = 0;
		}
		if (path[_])
			_++;
	}
	return (var);
}

void	if_path(t_main *shell, size_t _)
{
	struct stat	sb;

	stat(shell->cmds[_].cmd, &sb);
	if (errno)
	{
		err(errno, shell->cmds[_].cmd);
		free(shell->cmds[_].cmd);
		shell->cmds[_].cmd = NULL;
		shell->cmds[_].ex = 127;
		return ;
	}
	else if (S_ISDIR(sb.st_mode))
	{
		err(IS_A_DIR, shell->cmds[_].cmd);
		free(shell->cmds[_].cmd);
		shell->cmds[_].cmd = NULL;
		shell->cmds[_].ex = 126;
	}
	else if (access(shell->cmds[_].cmd, X_OK))
	{
		err(errno, shell->cmds[_].cmd);
		free(shell->cmds[_].cmd);
		shell->cmds[_].cmd = NULL;
		shell->cmds[_].ex = 126;
	}
}

void	if_cmd(t_main *shell, size_t _)
{
	void		*var;

	search_builtins(shell, _);
	if (shell->cmds[_].builtin_offset)
		return ;
	var = shell->cmds[_].cmd;
	errno = 0;
	shell->cmds[_].cmd = resolve_cmd(shell, shell->cmds[_].cmd, _);
	free(var);
	return ;
}

void	set_path(t_main *shell)
{
	size_t		_;

	_ = -1;
	while (++_ < shell->cmd_ct)
	{
		if (!shell->cmds[_].args)
			continue ;
		if (!ft_strchr(shell->cmds[_].cmd, '/'))
			if_cmd(shell, _);
		else
			if_path(shell, _);
	}
}
