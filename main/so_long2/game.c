#include "game.h"
#include <signal.h>

int draw(int x, int y, void *pt, t_game *s_game)
{

	mlx_put_image_to_window(s_game->mlx_p, s_game->w_p, pt, x * 16, y * 16);
	p("w %d, h%d\n", s_game->w, s_game->h);
	

	return (0);
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
			if (((char *)(findex(s_game->map, i)->content))[j] == '1')
				draw(j, i, s_game->wall, s_game);
			else if(((char *)(findex(s_game->map, i)->content))[j] == '0')
				draw(j, i, s_game->bcgr, s_game);
			else if (((char *)(findex(s_game->map, i)->content))[j] == 'E')
				draw(j, i, s_game->exit, s_game);
			else if (((char *)(findex(s_game->map, i)->content))[j] == 'P')
				draw(j, i, s_game->plyr, s_game);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	events(int k, struct s_game *param)
{
	if (k == 13)
		move('w', param);
	if (k == 0)
		move('a', param);
	p("<%d> ", k);
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
