/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:23:25 by ahkalama          #+#    #+#             */
/*   Updated: 2023/01/28 14:02:41 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_new_left_str(char *left)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (left[i] && left[i] != '\n')
		i++;
	if (!left[i])
	{
		free(left);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(left) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (left[i])
		str[j++] = left[i++];
	str[j] = '\0';
	free(left);
	return (str);
}

char	*ft_get_line(char *left)
{
	int		i;
	char	*str;

	i = 0;
	if (!left[i])
		return (NULL);
	while (left[i] && left[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1 + (ft_strchr(left, '\n') && 1)));
	if (!str)
		return (NULL);
	i = 0;
	while (left[i] && left[i] != '\n')
	{
		str[i] = left[i];
		i++;
	}
	if (left[i] == '\n')
	{
		str[i] = left[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_read_to_left_str(int fd, char *left)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(left, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		left = ft_strjoin(left, buff);
	}
	free(buff);
	return (left);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*left[256];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left[fd] = ft_read_to_left_str(fd, left[fd]);
	if (!left[fd])
		return (NULL);
	str = ft_get_line(left[fd]);
	left[fd] = ft_new_left_str(left[fd]);
	return (str);
}
// int	main()
// {
// 	int fd = open("test.txt", O_RDONLY);
// 	int fd2 = open("test2.txt", O_RDONLY);
// 	int resfd = open("result.txt", O_RDWR);
//  	char  *line;
// 	for (int i = 0; i < 2; i++) {
// 		if (i%2)
// 			line = get_next_line(fd2);
// 		else
// 			line = get_next_line(fd);
//  		write(resfd, line, ft_strlen(line));
// 	}
// }