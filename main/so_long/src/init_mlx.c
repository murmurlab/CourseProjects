/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 03:37:38 by ahbasara          #+#    #+#             */
/*   Updated: 2024/12/10 03:45:01 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

// enemy tex/tt/enemy.xpm
// player tex/tt/person.xpm
// wall tex/tt/wall.xpm
// collectable tex/tt/coin1.xpm
// collectable tex/tt/coin2.xpm
// collectable tex/tt/coin3.xpm
// collectable tex/tt/coin4.xpm
// collectable tex/tt/coin5.xpm
// collectable tex/tt/coin6.xpm
// floor tex/tt/floor.xpm
// exit tex/tt/bank.xpm

static char	*const		(g_text_match[6])[FPS] = {
[0] = {
[0] = "tex/tt/floor.xpm",
[1] = "tex/tt/floor.xpm",
[2] = "tex/tt/floor.xpm",
[3] = "tex/tt/floor.xpm",
[4] = "tex/tt/floor.xpm",
[5] = "tex/tt/floor.xpm",
},
[1] = {
[0] = "tex/tt/person.xpm",
[1] = "tex/tt/person.xpm",
[2] = "tex/tt/person.xpm",
[3] = "tex/tt/person.xpm",
[4] = "tex/tt/person.xpm",
[5] = "tex/tt/person.xpm",
},
[2] = {
[0] = "tex/tt/wall.xpm",
[1] = "tex/tt/wall.xpm",
[2] = "tex/tt/wall.xpm",
[3] = "tex/tt/wall.xpm",
[4] = "tex/tt/wall.xpm",
[5] = "tex/tt/wall.xpm",
},
[3] = {
[0] = "tex/tt/bank.xpm",
[1] = "tex/tt/bank.xpm",
[2] = "tex/tt/bank.xpm",
[3] = "tex/tt/bank.xpm",
[4] = "tex/tt/bank.xpm",
[5] = "tex/tt/bank.xpm",
},
[4] = {
[0] = "tex/tt/coin1.xpm",
[1] = "tex/tt/coin2.xpm",
[2] = "tex/tt/coin3.xpm",
[3] = "tex/tt/coin4.xpm",
[4] = "tex/tt/coin5.xpm",
[5] = "tex/tt/coin6.xpm",
},
[5] = {
[0] = "tex/tt/enemy.xpm",
[1] = "tex/tt/enemy.xpm",
[2] = "tex/tt/enemy.xpm",
[3] = "tex/tt/enemy.xpm",
[4] = "tex/tt/enemy.xpm",
[5] = "tex/tt/enemy.xpm",
},
};

t_err	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		return (game->err = _E_ALLOC_MLX);
	ft_printf("map size: %d x %d\n", game->map.w, game->map.h);
	game->win = mlx_new_window(\
		game->mlx, game->map.w * RES, game->map.h * RES, "so_long");
	if (game->win == NULL)
		return (game->err = _E_ALLOC_MLX);
	if (open_textures(game))
		return (game->err);
	mlx_do_key_autorepeatoff(game->mlx);
	mlx_hook(game->win, 17, 0, exit_game, game);
	mlx_hook(game->win, 2, 0, key_down, game);
	mlx_hook(game->win, 3, 0, key_up, game);
	mlx_loop_hook(game->mlx, loop_hook, game);
	mlx_loop(game->mlx);
	return (_E_0);
}

t_err	open_textures(t_game *game)
{
	int	text_idx;
	int	frame_idx;

	text_idx = 0;
	while (text_idx < 6)
	{
		frame_idx = 0;
		while (frame_idx < FPS)
		{
			game->img[text_idx][frame_idx] = mlx_xpm_file_to_image(\
				game->mlx, g_text_match[text_idx][frame_idx],
					&(int){0}, &(int){0});
			if (game->img[text_idx][frame_idx] == NULL)
				return (game->err = _E_ALLOC_MLX);
			frame_idx++;
		}
		text_idx++;
	}
	return (_E_0);
}
