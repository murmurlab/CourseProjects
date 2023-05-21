/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yciftci <yciftci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 22:34:51 by yciftci           #+#    #+#             */
/*   Updated: 2023/01/09 18:02:17 by yciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(char *map_name)
{
	char	**map;
	int		x_len;
	int		i;
	int		fd;

	i = 0;
	x_len = map_x_len(map_name);
	map = (char **)malloc(sizeof(char *) * (map_x_len(map_name) + 1));
	fd = open(map_name, O_RDONLY);
	while (i < x_len)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

int	map_y_len(char **map)
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	ret = 0;
	while (map[i][ret] && map[i][ret] != '\n')
		ret++;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
			j++;
		if (j != ret)
			return (0);
		i++;
	}
	return (ret);
}

int	map_x_len(char *map_name)
{
	int		ctrl;
	char	*tmp;
	int		len;

	len = 0;
	tmp = NULL;
	ctrl = open(map_name, O_RDONLY);
	if (!tmp)
	{
		tmp = get_next_line(ctrl);
		if (tmp)
			len++;
	}
	while (tmp)
	{
		free (tmp);
		tmp = get_next_line(ctrl);
		if (tmp)
			len++;
	}
	close(ctrl);
	free (tmp);
	return (len);
}

int	is_line(char **map, char *map_name, int i, int j)
{
	int	x_len;
	int	y_len;

	x_len = map_x_len(map_name);
	y_len = map_y_len(map);
	while (i < x_len)
	{
		j = 0;
		while (j < y_len)
		{
			if (i == 0 || i == x_len - 1)
			{
				if (map[i][j] != '1')
					return (0);
			}
			else
			{
				if ((j == 0 || j == y_len - 1) && map[i][j] != '1')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
