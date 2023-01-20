/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 05:34:48 by codespace         #+#    #+#             */
/*   Updated: 2023/01/20 16:17:35 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	init(int *fd, char **line, char **buffer, ssize_t *err)
{
	if (0 > *fd)
		return (1);
	*line = malloc(1);
	line[0][0] = 0;
	if (!*buffer)
	{
		*buffer = malloc(BUFFER_SIZE);
		*err = read(*fd, *buffer, BUFFER_SIZE);
		if (!*err || (int)*err == -1)
		{
			free(*buffer);
			free(*line);
			return (1);
		}
	}
	return (0);
}

int	check(char *buffer, size_t *buffer_index, char **line, size_t *index)
{
	if (buffer[*buffer_index] == '\n')
	{
		*line = ft_strjoin(*line, ft_substr(buffer, *index, (*buffer_index
						- *index + 1)), 1);
		(*buffer_index)++;
		*index = *buffer_index;
		return (1);
	}
	return (0);
}

char	norminette(char **buffer, char **line, ssize_t *err, int *fd)
{
	static size_t	buffer_index;
	static size_t	index;

	while (1)
	{
		if (check(*buffer, &buffer_index, line, &index))
			break ;
		if (buffer_index == BUFFER_SIZE)
		{
			*line = ft_strjoin(*line, ft_substr(*buffer, index, buffer_index
						- index), 1);
			free(*buffer);
			*buffer = malloc(BUFFER_SIZE);
			*err = read(*fd, *buffer, BUFFER_SIZE);
			if (!*err)
				return (1);
			buffer_index = -1;
			index = 0;
		}
		buffer_index++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char		*buffer = NULL;
	char			*line;
	ssize_t			err;
	char			norminette_return_value;

	if (init(&fd, &line, &buffer, &err))
		return (NULL);
	norminette_return_value = norminette(&buffer, &line, &err, &fd);
	if (norminette_return_value)
		return ("");
	return (line);
}
