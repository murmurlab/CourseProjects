/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:09:19 by ahbasara          #+#    #+#             */
/*   Updated: 2023/02/17 19:07:04 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "../libft/libft.h"

char	**_message;

void	to_bit(int sig)
{
	(void)sig;
	static int	i = 0;

	if (i == 8)
	{
		if (!*(_message + 2))
		{		
			return ;
		}
		(*(2 + _message))++;
		i = 0;
	}
	if ((**(_message + 2) >> i) & 1)
		kill(*(int *)*(_message + 1), SIGUSR2);
	else
		kill(*(int *)*(_message + 1), SIGUSR1);
	i++;
}

int	main(int argc, char **argv)
{
	(void)argc;
	int	pid;

	pid = ft_atoi(argv[1]);
	_message = argv;
	*(_message + 1) = (char *)&pid;
	signal(SIGUSR1, to_bit);
	usleep(200);
	to_bit(111);
	while (1)
		pause();
}
