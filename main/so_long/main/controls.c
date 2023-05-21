/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:48:23 by yciftci           #+#    #+#             */
/*   Updated: 2023/05/20 22:15:28 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_data *d, int x, int y)
{
	int	p_x;
	int	p_y;

	p_x = d->p->x;
	p_y = d->p->y;
	mlx_put_image_to_window(d->m_p, d->w_p, d->p_img, y * IQW, x * IQW);
	mlx_put_image_to_window(d->m_p, d->w_p, d->bg_img, p_y * IQW, p_x * IQW);
	d->map[x][y] = 'P';
	d->map[p_x][p_y] = '0';
}

void	control_up(t_data *d, char direction)
{
	int	x;
	int	y;

	loc_init(&x, &y, d->p, direction);
	d->step++;
	ft_printf("%d\n", d->step);
	if (d->map[x][y] == '1')
		return ;
	if (d->map[x][y] == '0')
		move(d, x, y);
	if (d->map[x][y] == 'C')
	{
		move(d, x, y);
		d->coin_count--;
	}
	if ((x == d->exit_l->x && y == d->exit_l->y) && (!d->coin_count))
		exit(write(1, "Helal!", sizeof("Helal!")));
	if ((x == d->exit_l->x && y == d->exit_l->y) && (d->coin_count))
		put_exit(d, d->map, d->p, direction);
}

int	controller(int key, t_data *data)
{
	if (key == 13)
		control_up(data, 'u');
	else if (key == 2)
		control_up(data, 'r');
	else if (key == 0)
		control_up(data, 'l');
	else if (key == 1)
		control_up(data, 'd');
	else if (key == 53)
		exit(write(1, "Oyunu Kapattiniz! Vaz mi gectin?", 32));
	free(data->p);
	free(data->exit_l);
	data->p = p_locate(data->map);
	data->exit_l = e_locate(data->map);
	return (0);
}
