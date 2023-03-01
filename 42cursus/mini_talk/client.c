/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:09:19 by ahbasara          #+#    #+#             */
/*   Updated: 2023/03/01 14:37:27 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

typedef struct s_data
{
	char	*message;
	int		pid;
	size_t	len;
}	t_data;

t_data	g_data;

void	send(int signal)
{
	static int	i = 8;
	// ft_printf("g %d\n", (*g_data.message >> i));

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

void	send_head(int aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa)
{
	static int left_shift = sizeof(size_t) * 8;

	(void)aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa;
	if (left_shift-- > 0)
	{
		if ((g_data.len >> left_shift) & 1)
			kill(g_data.pid, SIGUSR2);
		else
			kill(g_data.pid, SIGUSR1);
	}
	else
	{
		signal(SIGUSR1, send);
		send(123);
	}
}

int	main(int argc, char **argv)
{
	char	i;

	i = sizeof(size_t) * 8;
	(void)argc;
	g_data.pid = ft_atoi(argv[1]);
	g_data.message = argv[2];
	g_data.len = ft_strlen(g_data.message);
	signal(SIGUSR1, send_head);
	send_head(123);
	while (1)
		pause();
}
