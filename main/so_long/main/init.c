/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:06:36 by yciftci           #+#    #+#             */
/*   Updated: 2023/05/20 22:16:57 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	c_counter(char **map, char *map_name)
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
			if (map[x][y] == 'C')
				rvalue++;
			y++;
		}
		x++;
	}
	return (rvalue);
}

int	e_counter(char **map, char *map_name)
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
			if (map[x][y] == 'E')
				rvalue++;
			y++;
		}
		x++;
	}
	return (rvalue);
}

void	data_init(t_data *data, char *map_name)
{
	int	w;
	int	h;
	int	y_len;
	int	x_len;

	data->map = read_map(map_name);
	w = map_y_len(data->map) * IQW;
	h = map_x_len(map_name) * IQW;
	data->m_p = mlx_init();
	data->w_p = mlx_new_window(data->m_p, w, h, "Agrili Keno!");
	data->coin_count = c_counter(data->map, map_name);
	data->exit_control = e_counter(data->map, map_name);
	data->p = p_locate(data->map);
	data->exit_l = e_locate(data->map);
	data->step = 0;
	data->bg_img = mlx_xpm_file_to_image(data->m_p, BG, &w, &h);
	data->w_img = mlx_xpm_file_to_image(data->m_p, W, &w, &h);
	data->p_img = mlx_xpm_file_to_image(data->m_p, P, &w, &h);
	data->e_img = mlx_xpm_file_to_image(data->m_p, E, &w, &h);
	data->c_img = mlx_xpm_file_to_image(data->m_p, C, &w, &h);
}
