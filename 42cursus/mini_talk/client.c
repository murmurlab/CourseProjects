/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:09:19 by ahbasara          #+#    #+#             */
/*   Updated: 2023/02/20 08:50:11 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

typedef struct s_data
{
	char	*message;
	int		pid;
}	t_data;

t_data	g_data;

void	handler(int signal)
{
	static int	i = 8;

	(void)signal;
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
	(void)argc;
	g_data.pid = ft_atoi(argv[1]);
	g_data.message = argv[2];
	signal(SIGUSR1, handler);
	handler(123);
	while (1)
		pause();
}
