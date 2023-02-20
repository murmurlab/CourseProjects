/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:09:19 by ahbasara          #+#    #+#             */
/*   Updated: 2023/02/20 08:32:44 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************ */
/*	credit by				*/
/*		ahbasara & oyumusak	*/
/* ************************ */

#include <signal.h>
#include <unistd.h>
#include "../libft/libft.h"
#include "../ft_printf/spagetti/ft_printf.h"

typedef struct s_data
{
	char	*message;
	int		pid;
}	t_data;

t_data	g_data;

void	to_bit(int signal, siginfo_t *info, void	*uc)
{
	static int	i = 8;

	if (i < 1)
	{
		if (!*g_data.message)
		{
			exit(0);
		}
		g_data.message++;
		i = 8;
	}
	i--;
	if ((*g_data.message >> i) & 1)
	{
		kill(g_data.pid, SIGUSR2);
	}
	else
	{
		kill(g_data.pid, SIGUSR1);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	act;

	(void)argc;
	g_data.pid = ft_atoi(argv[1]);
	g_data.message = argv[2];
	act.sa_sigaction = to_bit;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	to_bit(123, NULL, NULL);
	while (1)
		pause();
}
