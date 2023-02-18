/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:09:17 by ahbasara          #+#    #+#             */
/*   Updated: 2023/02/17 19:58:13 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "../ft_printf/spagetti/ft_printf.h"

void	handler(int signal, siginfo_t *info, void	*uc)
{
	//usleep(10000);
	//ft_printf("aaaaa %d\n", signal);
	(void)uc;
	static unsigned char	c;
	static unsigned char	ct;

	//ft_printf("%d\n",ct); 
	c |= (signal == SIGUSR2);
	if (++ct == 8)
	{
		write(1, &c, 1);
		ct = 0;
		c = 0;
	}
	else
		c <<= 1;
	//ft_printf("sending feedback to %d pid\n",info->si_pid);
	usleep(200);
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	act;
	int					pid;
	
	pid = getpid();
	act.sa_sigaction = handler;
	act.sa_flags = SA_SIGINFO;

	ft_printf("%d\n", pid);

	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);

	while (1)
		pause();
}
