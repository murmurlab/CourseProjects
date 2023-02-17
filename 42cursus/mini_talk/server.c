/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:09:17 by ahbasara          #+#    #+#             */
/*   Updated: 2023/02/17 19:06:54 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "../ft_printf/spagetti/ft_printf.h"

void	handler(int signal, siginfo_t *info, void	*uc)
{
	ft_printf("aaaaa %d\n", signal);
	(void)uc;
	static char	c;
	static char	ct;

	c |= (signal == SIGUSR2);
	if (++ct == 8)
	{
		write(1, &c, 1);
		ct = 0;
	}
	else
		c = (c << 1);
	ft_printf("sending feedback to %d pid\n",info->si_pid);
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	act;
	int					pid;
	
	pid = getpid();
	act.sa_sigaction = handler;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	ft_printf("%d\n", pid);
	while (1)
	{
		pause();
	}
	ft_printf("asda\n");
}
