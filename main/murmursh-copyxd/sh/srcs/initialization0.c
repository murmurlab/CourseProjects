/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization0.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 20:14:54 by ahbasara          #+#    #+#             */
/*   Updated: 2024/10/29 15:23:11 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	ctrl_c(int sig)
{
	(void)sig;
	if (!g_qsignal)
	{
		printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	tcsa(void)
{
	struct termios	term1;

	if (tcgetattr(STDIN_FILENO, &term1) != 0)
		exit((perror(SHELLSAY TCGA_ERR_MSG), -1));
	term1.c_cc[VQUIT] = _POSIX_VDISABLE;
	term1.c_lflag |= ECHOE | ICANON;
	term1.c_lflag |= ECHOCTL;
	if (tcsetattr(STDIN_FILENO, TCSANOW, &term1) != 0)
		exit((perror(SHELLSAY TCSA_ERR_MSG), -1));
	if (tcgetattr(STDIN_FILENO, &term1) != 0)
		exit((perror(SHELLSAY TCGA_ERR_MSG), -1));
}

int	initialization(t_main *shell)
{
	tcsa();
	shell->vars = NULL;
	if (env2list(shell))
		return (1);
	ft_bzero(shell->increases, INT8_MAX);
	shell->increases['"'] = (char)2;
	shell->increases['\''] = (char)2;
	shell->cmds = NULL;
	shell->cmd_ct = 0;
	shell->has_cmd = 0;
	shell->current = 0;
	shell->set_val[0] = set_cmd;
	shell->set_val[1] = set_arg;
	shell->set_val[2] = set_in;
	shell->set_val[3] = set_out;
	shell->set_val[4] = set_heredoc;
	shell->set_val[5] = none;
	if (chdir(get_var_ref(shell, "PWD", 3)))
		perror(SHELLSAY CHDIR_ERR);
	if (SIG_ERR == signal(SIGINT, ctrl_c))
		return (perror(SHELLSAY SIGNAL_SET_ERR), 1);
	if (set(shell, ft_strdup("?=0")))
		perror(SHELLSAY INIT_VAR_ERR);
	return (g_qsignal = 0);
}
