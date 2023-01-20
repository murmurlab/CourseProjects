/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 00:49:51 by codespace         #+#    #+#             */
/*   Updated: 2023/01/20 12:10:19 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
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




	l = get_next_line(fd);






	while (i++ < 21)
	{
 		l = get_next_line(fd);
		if (l)
			write(1, l, ft_strlen(l));
	}
	close(fd);
}
