/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_find_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yciftci <yciftci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:09:06 by yciftci           #+#    #+#             */
/*   Updated: 2023/01/20 12:31:06 by yciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/libft/libft.h"
#include "so_long.h"

t_stack	*p_locate(char **map)
{
	t_stack	*rvalue;
	int		x_counter;
	int		y_counter;

	rvalue = (t_stack *)malloc(sizeof(t_stack));
	x_counter = 0;
	while (map[x_counter])
	{
		y_counter = 0;
		while (map[x_counter][y_counter] != '\0')
		{
			if (map[x_counter][y_counter] == 'P')
			{
				rvalue->x = x_counter;
				rvalue->y = y_counter;
				rvalue->next = NULL;
				return (rvalue);
			}
			y_counter++;
		}
		x_counter++;
	}
	return (NULL);
}

t_stack	*c_locate(char **map, char *map_name)
{
	t_stack	*rvalue;
	int		x_counter;
	int		y_counter;

	rvalue = (t_stack *)malloc(sizeof(t_stack));
	x_counter = 0;
	while (x_counter < map_x_len(map_name))
	{
		y_counter = 0;
		while (map[x_counter][y_counter] != '\0')
		{
			if (map[x_counter][y_counter] == 'C'
				|| map[x_counter][y_counter] == 'E')
			{
				rvalue->x = x_counter;
				rvalue->y = y_counter;
				rvalue->next = NULL;
				return (rvalue);
			}
			y_counter++;
		}
		x_counter++;
	}
	return (NULL);
}

int	collectable_counter(char **map, char *map_name)
{
	int	rvalue;
	int	x;
	int	y;

	x = 0;
	rvalue = 0;
	while (x < map_x_len(map_name))
	{
		y = 0;
		while (map[x][y] != '\0')
		{
			if (map[x][y] == 'C' || map[x][y] == 'E')
				rvalue++;
			y++;
		}
		x++;
	}
	return (rvalue);
}

int	is_turnout(char **map, int x, int y)
{
	int	counter;

	counter = 0;
	if (map[x + 1][y] == '0' || map[x + 1][y] == 'E' || map[x + 1][y] == 'C')
		counter++;
	if (map[x - 1][y] == '0' || map[x - 1][y] == 'E' || map[x - 1][y] == 'C')
		counter++;
	if (map[x][y + 1] == '0' || map[x][y + 1] == 'E' || map[x][y + 1] == 'C')
		counter++;
	if (map[x][y - 1] == '0' || map[x][y - 1] == 'E' || map[x][y - 1] == 'C')
		counter++;
	return (counter);
}

char	**create_tmp_map(char *map_name)
{
	char	**r_map;
	int		i;
	int		j;

	r_map = read_map(map_name);
	i = 0;
	while (i < map_x_len(map_name))
	{
		j = 0;
		while (j < map_y_len(r_map))
		{
			if (r_map[i][j] == 'C' || r_map[i][j] == 'E'
				|| r_map[i][j] == 'P')
				r_map[i][j] = '0';
			j++;
		}
		i++;
	}
	return (r_map);
}
