#include "game.h"
#include <signal.h>

int draw_block(int x, int y, t_game *s_game, void *img)
{
	if (img)
		return (mlx_put_image_to_window(s_game->mlx_p, s_game->w_p, img, x * 16, y * 16));
	if (((char *)(findex(s_game->map, y)->content))[x] == '1')
		mlx_put_image_to_window(s_game->mlx_p, s_game->w_p, s_game->wall, x * 16, y * 16);
	else if(((char *)(findex(s_game->map, y)->content))[x] == '0')
		mlx_put_image_to_window(s_game->mlx_p, s_game->w_p, s_game->bcgr, x * 16, y * 16);
	else if (((char *)(findex(s_game->map, y)->content))[x] == 'E')
		mlx_put_image_to_window(s_game->mlx_p, s_game->w_p, s_game->exit, x * 16, y * 16);
	else if (((char *)(findex(s_game->map, y)->content))[x] == 'P')
		mlx_put_image_to_window(s_game->mlx_p, s_game->w_p, s_game->plyr, x * 16, y * 16);
	p("draw_block: w<%d>, h<%d>\n", s_game->w, s_game->h);
	return (1);
}

int draw_all(t_game *s_game)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < s_game->y_len)
	{
		while (j < s_game->y_len)
		{
			draw_block(j, i, s_game, NULL);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	events(int k, struct s_game *param)
{
	param->select = k;
	p("key<%d> ", k);
	update(param);
	return (0);
}

int	init1(t_game *s_game, char **c)
{
	struct s_read_map	s_read_map;

	s_read_map.s_game = s_game;
	s_game->colls = 0;
	s_read_map.end = 0;
	s_read_map.p_p = 0;
	s_read_map.exit_code = 0;
	s_read_map.count_E = 0;
	s_read_map.count_P = 0;
	s_game->my_colls = 0;
	s_game->end = 0;
	s_game->bcgr = mlx_xpm_file_to_image(s_game->mlx_p, "assets/bg.xpm", &s_game->w, &s_game->h);
	s_game->plyr = mlx_xpm_file_to_image(s_game->mlx_p, "assets/ghasta.xpm", &s_game->w, &s_game->h);
	s_game->wall = mlx_xpm_file_to_image(s_game->mlx_p, "assets/wall.xpm", &s_game->w, &s_game->h);
	s_game->exit = mlx_xpm_file_to_image(s_game->mlx_p, "assets/exit_1.xpm", &s_game->w, &s_game->h);
	s_game->coll = mlx_xpm_file_to_image(s_game->mlx_p, "assets/main_c.xpm", &s_game->w, &s_game->h);
	s_game->wasd[13][0] = 0;
	s_game->wasd[13][1] = -1;
	s_game->wasd[0][0] = -1;
	s_game->wasd[0][1] = 0;
	s_game->wasd[1][0] = 0;
	s_game->wasd[1][1] = 1;
	s_game->wasd[2][0] = 1;
	s_game->wasd[2][1] = 0;
	s_read_map.exit_code = load_map(&s_read_map, c);
	if (s_read_map.exit_code)
	{
		p("error load map: %d\n", s_read_map.exit_code);
		return (1);
	}
	draw_all(s_game);
	mlx_key_hook(s_game->w_p, &events, s_game);
	s_read_map.exit_code = 0; //validate_map(s_game);
	if (s_read_map.exit_code)
	{
		p("error load map: %d\n", s_read_map.exit_code);
		return (1);
	}
	return (0);
}

int	main(int c, char *v[])
{
	t_game				*s_game;

	s_game = malloc(sizeof(t_game));
	p("BUFFER_SIZE: %d\n", BUFFER_SIZE);
	s_game->mlx_p = mlx_init();
	s_game->w_p = mlx_new_window(s_game->mlx_p, 500, 500, "game");
	if (init1(s_game, v))
		return (1);
	mlx_loop(s_game->mlx_p);
}
