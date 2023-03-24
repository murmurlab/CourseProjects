/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:09:19 by ahbasara          #+#    #+#             */
/*   Updated: 2023/03/04 04:08:39 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

typedef struct s_data
{
	char	*message;
	int		pid;
	size_t	len;
	int		stat;
}	t_data;

t_data	g_data;

void	send(int a)
{
	static int	i = 8;

	(void)a;
	if (!i)
	{
		if (!*g_data.message)
			exit(0);
		if (g_data.stat)
			*(g_data.message + 1) = 0;
		g_data.message++;
		i = 8;
	}
	i--;
	if ((*g_data.message >> i) & 1)
		kill(g_data.pid, SIGUSR2);
	else
		kill(g_data.pid, SIGUSR1);
}

void	send_head(int a)
{
	static int	left_shift = sizeof(size_t) * 8;

	(void)a;
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

void	end(int a)
{
	(void)a;
	g_data.stat = 1;
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (ft_printf("wrong arg count."));
	(void)argc;
	g_data.pid = ft_atoi(argv[1]);
	g_data.message = argv[2];
	g_data.len = ft_strlen(g_data.message);
	signal(SIGUSR1, send_head);
	signal(SIGINT, end);
	send_head(123);
	while (1)
		pause();
}
