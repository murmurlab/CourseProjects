/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:09:17 by ahbasara          #+#    #+#             */
/*   Updated: 2023/02/13 12:26:30 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

void	handler(int signal, siginfo_t *info, void	*uc)
{
	static char	c;
	static char	ct;

	c |= (signal == SIGUSR2);
	if (++ct == 8)
	{
		write(1, &c, 1);
		ct = 0;
	}
	else
		c << 1;
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	act;

	act.sa_sigaction = handler;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
}
