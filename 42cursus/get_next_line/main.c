/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 00:49:51 by codespace         #+#    #+#             */
/*   Updated: 2023/01/22 13:09:15 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

void funct()
{
	int		fd;
	int		i;
	char	*l;
	fd = open("file", O_RDONLY, 0);
	printf("fd: %d\n", fd);
	i = 0;
/* 
	l = malloc(1000);
	l[0] = read(1000, l, 44);
 */
	//fd = -1;
	while (i++ < 9)	
	{
 		l = get_next_line(fd);
		if (l)
		{
			write(1, l, ft_strlen(l));
			free(l);
		}
	}
	close(fd);
}

int	main(void)
{
	funct();
	system("leaks a.out");
}

//clang++ -D BUFFER_SIZE=1 -gdwarf-4 -D TIMEOUT_US=1000000 -g3 -ldl -std=c++11 -I utils/ -I.. -Wno-everything utils/sigsegv.cpp utils/color.cpp utils/check.cpp utils/gnl.cpp utils/leaks.cpp tests/mandatory.cpp ../get_next_line.o ../get_next_line_utils.o -o testes
