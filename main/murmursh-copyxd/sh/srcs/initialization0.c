#include "include.h"

void	coix(int sig)
{
	// sleep(1);
	// printf("%c%c", 8, 8);
	rl_on_new_line();
	// rl_replace_line("", 1);
	printf("\033[K");
	rl_redisplay();
	g_qsignal = 1;
}

covid	ctrl_c(int sig)
{
	if (!g_qsignal)
	{
		printf("\n");
		rl_replace_line("", 0); // set the current input to given string
		rl_on_new_line(); // set the current line to promt + input
		rl_redisplay(); // set the start of cursor to end		
	}
	else
		printf("\n");
	// printf(GREEN PROMT RESET);
}

void	tcsa()
{
	struct termios	term1;

	if (tcgetattr(STDIN_FILENO, &term1) != 0)
		exit((perror(SHELLSAY"tcgetattr() error"), -1));
	else
	{
		term1.c_cc[VQUIT] = _POSIX_VDISABLE;
		term1.c_lflag |= ECHOE;
		if (tcsetattr(STDIN_FILENO, TCSANOW, &term1) != 0)
			exit((perror(SHELLSAY"tcsetattr() error"), -1));
		if (tcgetattr(STDIN_FILENO, &term1) != 0)
			exit((perror(SHELLSAY"tcsetattr() error"), -1));
	}

}

int		initialization(t_main *shell)
{
	tcsa();
	shell->vars = NULL;
	if (env2list(shell))
		return (1);
	ft_bzero(shell->increases, INT8_MAX);
	shell->increases['"'] = (char)2;
	shell->increases['\''] = (char)2;
	shell->increases[0] = (char)0;
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
		perror(SHELLSAY"chdir failed");
	if (signal(SIGINT, ctrl_c))
		return (perror(SHELLSAY"set ^C signal handler failed"), 1);
	if (set(shell, ft_strdup("?=0")))
		perror(SHELLSAY"set $? to init value failed");
	return (g_qsignal = 0);
}
