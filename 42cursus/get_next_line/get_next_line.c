/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 05:34:48 by codespace         #+#    #+#             */
/*   Updated: 2023/01/20 10:47:12 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



char	*get_next_line(int fd)
{
	static char		*buffer = NULL;
	char			*line;
	static size_t	buffer_index;
	static size_t	index;
	ssize_t			err;

	if (0 > fd)
		return (NULL);
	line = malloc(1);
	line[0] = 0;
	if (!buffer)
	{
		buffer = malloc(BUFFER_SIZE);
		err = read(fd, buffer, BUFFER_SIZE);
		if (!err || (int)err == -1)
		{
			free(buffer);
			free(line);
			return (NULL);
		}
	}
	while (1)
	{
		//asdasd\nasd
		//asd\naaaaaa
		if (buffer[buffer_index] == '\n')
		{
			line = ft_strjoin(line, ft_substr(buffer, index, (buffer_index - index + 1)), 1);
			buffer_index++;
			index = buffer_index;
			break ;
		}
		if (buffer_index == BUFFER_SIZE)
		{
			line = ft_strjoin(line, ft_substr(buffer, index, buffer_index - index), 1);
			free(buffer);
			buffer = malloc(BUFFER_SIZE);
			err = read(fd, buffer, BUFFER_SIZE);
			if (!err)
				return ("");
			buffer_index = -1;
			index = 0;
		}
		buffer_index++;
	}
	return (line);
}
