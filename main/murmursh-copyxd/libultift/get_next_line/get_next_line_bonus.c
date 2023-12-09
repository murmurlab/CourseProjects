/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:11:10 by marvin            #+#    #+#             */
/*   Updated: 2023/10/30 14:30:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*first_read_b(int fd, char *buffer)
{
	char	*buff;
	int		rd_byte;

	rd_byte = 1;
	buff = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (!find_nl_char_b(buffer) && rd_byte != 0)
	{
		rd_byte = read (fd, buff, BUFFER_SIZE);
		if (rd_byte == -1)
		{
			free(buffer);
			free(buff);
			return (NULL);
		}
		buff[rd_byte] = '\0';
		buffer = strjoin_gnl_b(buffer, buff);
	}
	free (buff);
	return (buffer);
}

char	*get_next_line_b(int fd)
{
	char		*line;
	static char	*s_buffer[1024];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (0);
	s_buffer[fd] = first_read_b(fd, s_buffer[fd]);
	if (s_buffer[fd] == NULL)
		return (NULL);
	line = get_new_line_b(s_buffer[fd]);
	s_buffer[fd] = get_new_buffer_b(s_buffer[fd]);
	return (line);
}
