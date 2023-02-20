/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:09:17 by ahbasara          #+#    #+#             */
/*   Updated: 2023/02/20 17:40:38 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/* #include <fcntl.h>

int	fd; */

typedef struct s_data
{
	char	*buffer;
	size_t	len;
	int		pid_fb;
}	t_data;

t_data	g_data;

void	feedback(int signal, siginfo_t *info, void	*uc)
{
	static unsigned char	c;
	static unsigned char	ct = 8;
	static int				temp = 0;

	(void)uc;
	c |= (signal == SIGUSR2);
	if (!ct--)
	{
		write(1, &c, 1);
		ct = 8;
		c = 0;
	}
	else
		c <<= 1;
	if (temp == 0)
		temp = info->si_pid;
	if (temp != info->si_pid && info->si_pid != 0)
			temp = info->si_pid;
	kill(temp, SIGUSR1);
}

void	pre_handler(int signal, siginfo_t *info, void	*uc)
{
	static char		max_shift = sizeof(size_t) * 8;

	(void)uc;
	g_data.len |= (signal == SIGUSR2);
	if (max_shift-- == 1)
	{		
		g_data.len <<= 1;
		return ;
	}
	g_data.len <<= 1;
	if (g_data.pid_fb == 0)
		g_data.pid_fb = info->si_pid;
	if (g_data.pid_fb != info->si_pid && info->si_pid != 0)
		g_data.pid_fb = info->si_pid;
	kill(g_data.pid_fb, SIGUSR1);
	printf("v: %zu", g_data.len);
	fflush(stdout);
}

int	main(void)
{
	struct sigaction	act;
	int					pid;
	char				i;

	g_data.pid_fb = 0;
	i = sizeof(size_t) * 8;
	pid = getpid();
	act.sa_sigaction = pre_handler;
	act.sa_flags = SA_SIGINFO;
	ft_printf("%d\n", pid);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (i--)
		pause();
	act.sa_sigaction = feedback;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	kill(g_data.pid_fb, SIGUSR1);
	while (1)
		pause();
}
