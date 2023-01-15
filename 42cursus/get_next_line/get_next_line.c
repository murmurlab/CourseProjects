/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:48:55 by ahbasara          #+#    #+#             */
/*   Updated: 2023/01/15 00:53:09 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*buff = NULL;
	char			*line;
	size_t			len;

	line = malloc(1);
	line[0] = 0;
	len = 0;
	if (!buff)
	{
		buff = malloc(BUFFER_SIZE + 1);
		read(fd, buff, BUFFER_SIZE);
		buff[BUFFER_SIZE] = 0;
	}
	while (1)
	{// || (buff[len] == '\0')
		if (buff[len] == '\n')
		{
			line = ft_strjoin(line, ft_substr(buff, 0, len + 1));
			buff = &buff[len + 1];
			return (line);
		}
		if (len == BUFFER_SIZE - 1)
		{
			line = ft_strjoin(line, buff);
			buff = malloc(BUFFER_SIZE + 1);
			read(fd, buff, BUFFER_SIZE);
			buff[BUFFER_SIZE] = 0;
			len = -1;
		}
		len++;
	}
	return (line);
}
