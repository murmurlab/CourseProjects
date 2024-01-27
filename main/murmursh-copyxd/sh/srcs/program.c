/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 21:30:20 by ahbasara          #+#    #+#             */
/*   Updated: 2024/01/27 22:11:40 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"
#include <stdarg.h>

int		g_qsignal;

void	del(void *_)
{
	free(_);
}

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

void	reset(t_main *shell, t_execd *execd)
{
	if (execd)
	{
		clear_pipes(execd->fd, shell->cmd_ct);
		free(execd->pids);
		free(execd->exs);
	}
	clear_cmds(shell->cmds, shell->cmd_ct);
	free(shell->cmds);
	shell->cmd_ct = 0;
	shell->current = 0;
	shell->has_cmd = 0;
	shell->_ = 0;
	shell->cmds = NULL;
}

int		none(t_main *shell, char *string, int oflag)
{
	(void)shell;
	(void)string;
	(void)oflag;
	return (0);
}

int		run(t_main *data)
{
	MURMURTEST;

		// signal(SIGPIPE, event_sigpipe);
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
	// list_cmds(data);
	exe_cute_cat(data);
	return (0);
}

void	f2(t_list *node)
{
	free(node);
}



void	ex(t_main *shell)
{
	(void)shell;
}

int	main(void)
{
	extern char 	**environ;
	t_main			shell;

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
	{
		// rl_erase_empty_line = 1;
		// rl_already_prompted = 1;
		shell.line = readline(GREEN PROMT RESET);
		if (shell.line)
		{
			if (*shell.line)
				add_history(shell.line);
			if (shell.line[0] != 0)
			{
				shell._ = 0;
				if (run(&shell))
				{
					free(shell.line);
					break ;
				}
			}
			free(shell.line);
		}
		else
		{
			free(shell.line);
			if (1)
			{
				break ;
				printf("\033[A");
				printf(GREEN "" RESET);
				fflush(stdout);
			}
			printf("\n");
		}
		// rl_on_new_line();
		// free(shell.line);
	}
	ft_lstclear(&shell.vars, del);
}

/**
 * void	__attribute__((destructor))after_main()
 * {
 * 	pause();
 * }
 */
