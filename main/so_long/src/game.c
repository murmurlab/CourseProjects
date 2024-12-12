/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 03:07:55 by ahbasara          #+#    #+#             */
/*   Updated: 2024/12/10 04:51:42 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include <stdlib.h>

void	dispose_map_loader(t_map_ctl *map_ctl)
{
	ft_lstclear(&map_ctl->enemy, free);
	ft_lstclear(&map_ctl->x, free);
}

void	move(t_game *game, t_point u)
{
	t_point	new_pos;
	char	*target;

	new_pos = (t_point){game->map.player.x + u.x, game->map.player.y + u.y};
	target = findex(game->map.x, new_pos.y)->content;
	if (target[new_pos.x] == '1')
		return ;
	if (target[new_pos.x] == 'C')
	{
		game->map.colls--;
		((char *)findex(game->map.x, new_pos.y)->content)[new_pos.x] = '0';
	}
	if (target[new_pos.x] == 'E')
	{
		if (game->map.colls == 0)
			exit_game(game);
	}
	if (enemy_coll(game, new_pos))
		exit_game(game);
	if (u.x != 0 || u.y != 0)
	{
		game->map.movoment++;
		ft_printf("movoment: %d\n", game->map.movoment);
	}
	game->map.player = new_pos;
}

t_point	inv_point(t_point p)
{
	return ((t_point){-p.x, -p.y});
}

t_point	calculate_new_position(t_point *point, t_point unit_vector)
{
	return ((t_point){point->x + (unit_vector.x > 0) - (unit_vector.x < 0),
		point->y + (unit_vector.y > 0) - (unit_vector.y < 0)});
}

void	move_enemy(t_game *game)
{
	t_list		*node;
	t_point		*point;
	t_point		unit_vector;
	t_point		new_pos;
	char		*target;

	node = game->map.enemy;
	while (node != NULL)
	{
		point = node->content;
		unit_vector = (t_point){point->x - game->map.player.x,
			point->y - game->map.player.y};
		unit_vector = (t_point){-unit_vector.x, -unit_vector.y};
		new_pos = calculate_new_position(point, unit_vector);
		target = findex(game->map.x, new_pos.y)->content;
		if (target[new_pos.x] == '1')
		{
			node = node->next;
			continue ;
		}
		if (target[new_pos.x] == 'P')
			exit_game(game);
		*point = new_pos;
		node = node->next;
	}
}
