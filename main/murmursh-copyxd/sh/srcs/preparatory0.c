/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparatory0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 20:32:24 by ahbasara          #+#    #+#             */
/*   Updated: 2024/01/28 22:20:31 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	check_path(char **cmd, int *ex_err)
{
	struct stat	sb;

	errno = 0;
	stat(*cmd, &sb);
	if (errno)
	{
		free(*cmd);
		*cmd = NULL;
		return (0);
	}
	else if (S_ISDIR(sb.st_mode))
	{
		free(*cmd);
		*cmd = NULL;
		return (0);
	}
	else if (access(*cmd, X_OK))
	{
		err(errno, *cmd);
		*ex_err = 126;
	}
	return (1);
}

char	*resolve_cmd(t_main *shell, char *string, size_t _)
{
	char		*loc;
	char		*path;

	path = (get_ref(shell, "PATH"));
	loc = check_cmd(string, path, &shell->cmds[_].io_err);
	if (!loc)
	{
		err(CMD_NOTFND, string);
		shell->cmds[_].ex = 127;
	}
	return (loc);
}

char	*creat_cmd(char *path, size_t path_len, char *cmd)
{
	return (ft_strsjoin((t_merge *[]){\
		&(t_merge){path, path_len},
		&(t_merge){"/", 1},
		&(t_merge){cmd, ft_strlen(cmd)}, NULL
	}));
}

char	*check_cmd(char *cmd, char *path, int *ex_err)
{
	char		*var;
	size_t		_;

	if (!path)
		return (NULL);
	_ = 0;
	while ("")
	{
		if (path[_] == ':' || !path[_])
		{
			if (!path[_] && !_)
				break ;
			var = creat_cmd(path, _, cmd);
			if (check_path(&var, ex_err))
				break ;
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
