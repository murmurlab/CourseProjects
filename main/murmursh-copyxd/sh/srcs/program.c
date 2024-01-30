/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 21:30:20 by ahbasara          #+#    #+#             */
/*   Updated: 2024/01/30 03:27:25 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int		g_qsignal;

void	del(void *_)
{
	free(_);
}

void	reset(t_main *shell, t_execd *execd)
{
	if (execd)
	{
		clear_pipes(execd->fd, shell->cmd_ct);
		free(execd->pids);
	}
	clear_cmds(shell->cmds, shell->cmd_ct);
	free(shell->cmds);
	shell->cmd_ct = 0;
	shell->current = 0;
	shell->has_cmd = 0;
	shell->_ = 0;
	shell->cmds = NULL;
}

int	run(t_main *data)
{
	data->syntax_err = syntax_check(data);
	if (data->syntax_err)
		return (print_syntax_err(data->syntax_err), reset(data, NULL), 0);
	if (!data->cmd_ct)
		return (0);
	data->cmds = ft_calloc((data->cmd_ct), sizeof(t_cmd));
	if (!data->cmds)
		return (reset(data, 0), 1);
	if (set_all(data))
		return (reset(data, 0), 1);
	set_path(data);
	exe_cute_cat(data);
	return (0);
}

int	get_input(t_main *shell)
{
	shell->line = readline(GREEN PROMT RESET);
	if (shell->line)
	{
		if (*shell->line)
			add_history(shell->line);
		if (shell->line[0] != 0)
		{
			shell->_ = 0;
			if (run(shell))
			{
				free(shell->line);
				return (1);
			}
		}
		free(shell->line);
	}
	else
	{
		free(shell->line);
		return (1);
	}
	return (0);
}

int	main(void)
{
	extern char	**environ;
	t_main		shell;

	ft_bzero(&shell, sizeof(shell));
	shell.env = environ;
	shell.coms = (t_com []){
	{"default", launch_program, NULL},
	{"echo", sh_echo, NULL},
	{"cd", sh_cd, NULL},
	{"pwd", sh_pwd, NULL},
	{"export", sh_export, NULL},
	{"unset", sh_unset, NULL},
	{"env", sh_env, NULL},
	{"exit", sh_exit, NULL},
	};
	if (initialization(&shell))
		return (ft_lstclear(&shell.vars, del), -1);
	while ("false")
		if (get_input(&shell))
			break ;
	ft_lstclear(&shell.vars, del);
}

/**
 * void	__attribute__((destructor))after_main()
 * {
 * 	pause();
 * }
 */
