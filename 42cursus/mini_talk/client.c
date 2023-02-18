/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:09:19 by ahbasara          #+#    #+#             */
/*   Updated: 2023/02/17 20:04:28 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "../libft/libft.h"
#include "../ft_printf/spagetti/ft_printf.h"

typedef struct s_data
{
	char *message;
	int pid;
} t_data;

t_data g_data;

void	to_bit(int signal, siginfo_t *info, void	*uc)
{
	//usleep(10000);
	static int	i = 7;


	if (i == -1)
	{
		if (!*g_data.message)
		{		
			return ;
		}
		g_data.message++;
		i = 7;
	}
	if ((*g_data.message >> i) & 1)
		kill(g_data.pid, SIGUSR2);
	else
		kill(g_data.pid, SIGUSR1);
	i--;
	//ft_printf("asdasdf\n");
}

int	main(int argc, char **argv)
{
	(void)argc;
	struct sigaction	act;

	g_data.pid = ft_atoi(argv[1]);
	g_data.message = argv[2];
	act.sa_sigaction = to_bit;
	act.sa_flags = SA_SIGINFO;
	
	sigaction(SIGUSR1, &act, NULL);
	//usleep(200);
	to_bit(123, NULL, NULL);
	while (1)
		pause();
}
