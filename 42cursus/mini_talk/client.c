/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:09:19 by ahbasara          #+#    #+#             */
/*   Updated: 2023/02/13 12:12:11 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "../libft/libft.h"

char	**_message;

void	to_bit(int sig)
{
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
	if ((**(_message + 2) >> i) | 1)
		kill(**(_message + 1), SIGUSR2);
	else
		kill(**(_message + 1), SIGUSR1);
	i++;
}

void	send_char(char c)
{
	//to_bit(_message[i]);
}

int	main(int argc, char **argv)
{
	int	pid;

	pid = ft_atoi(argv[1]);
	_message = argv;
	*(_message + 1) = (char *)&pid;
	to_bit(0);
	signal(SIGUSR1, to_bit);
}
