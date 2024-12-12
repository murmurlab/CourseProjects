/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:22:23 by ahbasara          #+#    #+#             */
/*   Updated: 2024/12/10 04:05:40 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include <stdlib.h>

int	exit_game(t_game *game)
{
	dispose_game(game);
	exit(0);
}

int	img_idx(char c)
{
	return ((int [128]){
		['0'] = 0,
		['1'] = 2,
		['C'] = 4,
		['E'] = 3,
		['P'] = 1,
		['X'] = 5,
	}[(int)c]);
}

void	draw_enemies(t_game *game)
{
	t_list const	*node = game->map.enemy;
	t_point			point;

	while (node != NULL)
	{
		point = *(t_point *)(node->content);
		mlx_put_image_to_window(game->mlx, game->win,
			game->img[img_idx('X')][game->frame],
			point.x * RES, point.y * RES);
		node = node->next;
	}
}

// mlx_clear_window(game->mlx, game->win);
void	render_map(t_game *game)
{
	t_list const	*node = game->map.x;
	char			*line;
	int				x;
	int				y;

	y = 0;
	while (node != NULL)
	{
		line = node->content;
		x = 0;
		while (line[x] != '\0')
		{
			mlx_put_image_to_window(game->mlx, game->win,
				game->img[0][game->frame], x * RES, y * RES);
			mlx_put_image_to_window(game->mlx, game->win,
				game->img[img_idx(line[x])][game->frame],
				x * RES, y * RES);
			x++;
		}
		node = node->next;
		y++;
	}
	draw_enemies(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img[img_idx('P')] \
		[game->frame], game->map.player.x * RES, game->map.player.y * RES);
}

int	enemy_coll(t_game *game, t_point new_pos)
{
	t_list const	*node = game->map.enemy;
	t_point			point;

	while (node != NULL)
	{
		point = *(t_point *)(node->content);
		if ((point.x == new_pos.x && point.y == new_pos.y) || \
			(game->map.player.x == point.x && game->map.player.y == point.y))
			return (1);
		node = node->next;
	}
	return (0);
}
