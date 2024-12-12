/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 03:33:58 by ahbasara          #+#    #+#             */
/*   Updated: 2024/12/10 03:44:12 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

static const t_point	g_unit_move[280] = {
[13] = {0, -1},
[1] = {0, 1},
[0] = {-1, 0},
[2] = {1, 0},
};

int	key_up(int keycode, t_game *game)
{
	game->keys[keycode] = 0;
	if (game->keys[reverse_key(keycode)] == 0)
	{
		if (g_unit_move[keycode].y != 0)
			game->compansate.y = 0;
		if (g_unit_move[keycode].x != 0)
			game->compansate.x = 0;
	}
	else
	{
		if (g_unit_move[keycode].y != 0)
			game->compansate.y = g_unit_move[reverse_key(keycode)].y;
		if (g_unit_move[keycode].x != 0)
			game->compansate.x = g_unit_move[reverse_key(keycode)].x;
	}
	return (0);
}

int	key_down(int keycode, t_game *game)
{
	if (keycode == 53)
		exit_game(game);
	game->keys[keycode] = 1;
	if (g_unit_move[keycode].y != 0)
		game->compansate.y = g_unit_move[keycode].y;
	if (g_unit_move[keycode].x != 0)
		game->compansate.x = g_unit_move[keycode].x;
	return (0);
}

int	loop_hook(void *param)
{
	t_game *const	game = param;

	render_map(game);
	mlx_string_put(game->mlx, game->win, 10, 10, 0x00FFFFFF,
		ft_itoa(game->map.movoment));
	key_loop(game);
	game->frame++;
	game->tick++;
	if (game->tick == 2)
	{
		move_enemy(game);
		game->tick = 0;
	}
	if (game->frame == FPS)
		game->frame = 0;
	return (0);
}

int	reverse_key(int keycode)
{
	return ((int [280]){
		[13] = 1,
		[1] = 13,
		[0] = 2,
		[2] = 0,
	}[keycode]);
}

void	key_loop(t_game *game)
{
	move(game, (t_point){game->compansate.x, 0});
	move(game, (t_point){0, game->compansate.y});
}
