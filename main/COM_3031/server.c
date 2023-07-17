// ahbasara

#include "minitalk.h"

typedef struct s_data
{
	char				*buffer;
	size_t				len;
	size_t				len_now;
	int					pid_fb;
	struct sigaction	act;
}	t_data;

t_data	g_data;

void	pre_handler(int signal, siginfo_t *info, void	*uc);

void	print(void)
{
	write(1, g_data.buffer - (g_data.len_now), g_data.len_now);
	free(g_data.buffer - (g_data.len_now));
	g_data.len = 0;
	g_data.len_now = 0;
	g_data.act.sa_sigaction = pre_handler;
	sigaction(SIGUSR1, &g_data.act, NULL);
	sigaction(SIGUSR2, &g_data.act, NULL);
}

void	feedback(int signal, siginfo_t *info, void	*uc)
{
	static unsigned char	c;
	static unsigned char	ct = 7;

	(void)uc;
	c |= (signal == SIGUSR2);
	if (ct-- == 0)
	{
		if (c)
		{
			g_data.len_now++;
			*g_data.buffer++ = c;
		}
		else
			print();
		ct = 7;
		c = 0;
	}
	else
		c <<= 1;
	if (g_data.pid_fb == 0)
		g_data.pid_fb = info->si_pid;
	if (g_data.pid_fb != info->si_pid && info->si_pid != 0)
			g_data.pid_fb = info->si_pid;
	kill(g_data.pid_fb, SIGUSR1);
}

void	pre_handler(int signal, siginfo_t *info, void	*uc)
{
	static char		max_shift = sizeof(size_t) * 8;

	(void)uc;
	g_data.len |= (signal == SIGUSR2);
	if (max_shift == 1)
	{
		g_data.act.sa_sigaction = feedback;
		sigaction(SIGUSR1, &g_data.act, NULL);
		sigaction(SIGUSR2, &g_data.act, NULL);
		g_data.buffer = malloc(g_data.len + 1);
		g_data.buffer[g_data.len] = 0;
		max_shift = sizeof(size_t) * 8;
		kill(g_data.pid_fb, SIGUSR1);
		return ;
	}
	max_shift--;
	g_data.len <<= 1;
	if (g_data.pid_fb == 0)
		g_data.pid_fb = info->si_pid;
	if (g_data.pid_fb != info->si_pid && info->si_pid != 0)
		g_data.pid_fb = info->si_pid;
	kill(g_data.pid_fb, SIGUSR1);
}

int	main(void)
{
	int					pid;

	g_data.len_now = 0;
	g_data.len = 0;
	g_data.pid_fb = 0;

	pid = getpid();
	g_data.act.sa_sigaction = pre_handler;
	g_data.act.sa_flags = SA_SIGINFO;
	p("%d\n", pid);
	sigaction(SIGUSR1, &g_data.act, NULL);
	sigaction(SIGUSR2, &g_data.act, NULL);
	while (
		1
	)
		pause();
}
