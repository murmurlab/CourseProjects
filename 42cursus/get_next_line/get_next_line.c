/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 05:34:48 by codespace         #+#    #+#             */
/*   Updated: 2023/01/24 07:33:52 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*remainder = NULL;
	char			*buffer;
	char			*line;
	ssize_t			err;

	line = malloc(1);
	if (!remainder)
	{
		buffer = malloc(BUFFER_SIZE);
		err = read(fd, buffer, BUFFER_SIZE);		
	}
	if (fd < 0 || (err <= 0))
		return (NULL);
	if (remainder && ft_strchr(remainder, '\n'))
	while (!ft_strchr(buffer, '\n'))
	{
		
		ft_strjoin(line, buffer, 1);
	}
	return (line);
}
