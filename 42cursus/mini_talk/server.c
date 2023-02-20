/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:09:17 by ahbasara          #+#    #+#             */
/*   Updated: 2023/02/20 08:54:34 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

#include <fcntl.h>

int	fd;

void	handler(int signal, siginfo_t *info, void	*uc)
{
	static unsigned char	c;
	static unsigned char	ct;
	static int				temp = 0;

	(void)uc;
	c |= (signal == SIGUSR2);
	if (++ct == 8)
	{
		write(fd, &c, 1);
		ct = 0;
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

int	main(void)
{
	struct sigaction	act;
	int					pid;

	fd = open("o.txt", 777);
	pid = getpid();
	act.sa_sigaction = handler;
	act.sa_flags = SA_SIGINFO;
	ft_printf("%d\n", pid);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
	{
		pause();
	}
}
