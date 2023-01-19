/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:48:55 by ahbasara          #+#    #+#             */
/*   Updated: 2023/01/19 07:07:29 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line2(int fd)
{
	static char		*buff = NULL;
	char			*line;
	size_t			len;
	static char		*tmp;
	static size_t	readed;

	line = malloc(1);
	line[0] = 0;
	if (!buff)
	{
		buff = malloc(BUFFER_SIZE + 1);
		readed = read(fd, buff, BUFFER_SIZE);
		if (!readed || (int)readed == -1)
		{
			free(buff);
			free(line);
			return (NULL);
		}
		buff[BUFFER_SIZE] = 0;
		tmp = buff;
	}
	len = 0;
	while (1)
	{// || (buff[len] == '\0')
		if (len == readed)
		{
			line = ft_strjoin(line, buff, 0);
			free(tmp);
			if (readed < BUFFER_SIZE)
				return (line);
			buff = malloc(BUFFER_SIZE + 1);
			readed = read(fd, buff, BUFFER_SIZE);
			buff[BUFFER_SIZE] = 0;
			len = -1;
		}
		if (buff[len] == '\n')
		{
			line = ft_strjoin(line, ft_substr(buff, 0, len + 1), 1);
			buff = &buff[len + 1];
			return (line);
		}
		len++;
	}
	return (line);
}
