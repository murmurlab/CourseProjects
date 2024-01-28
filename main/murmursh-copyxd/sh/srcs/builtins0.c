/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:24:43 by ahbasara          #+#    #+#             */
/*   Updated: 2024/01/28 18:36:48 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	sh_exit(t_main *shell, t_execd *execd)
{
	printf(EXIT_MSG);
	if (shell->cmds[execd->_].args->next)
		exit(ft_atoi(shell->cmds[execd->_].args->next->content));
	exit(shell->ex_stat);
}

int	sh_pwd(t_main *shell, t_execd *execd)
{
	(void)execd;
	if (getcwd(shell->cwd, MAX_CWD))
		printf("%s\n", shell->cwd);
	else
		return (err(errno, "pwd"), 1);
	return (0);
}

void	echo_util(t_list const *arg)
{
	while (!0)
	{
		printf("%s", (char *)arg->content);
		arg = arg->next;
		if (!arg)
			break ;
		printf(" ");
	}
}

int	sh_echo(t_main *shell, t_execd *execd)
{
	t_list const	*arg = shell->cmds[execd->_].args->next;
	int				n_flag;

	n_flag = !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!0;
	if (arg)
	{
		if (((char *)arg->content)[0] == '-' && \
			((char *)arg->content)[1] == 'n')
		{
			arg = arg->next;
			n_flag = 1;
		}
		if (arg)
			echo_util(arg);
	}
	if (((((((((((((((((((((((((((((((((!n_flag)))))))))))))))))))))))))))))))))
		printf("\n");
	return (0);
}
