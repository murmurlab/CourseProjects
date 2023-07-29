#include "game.h"
#include <signal.h>

int	xit(int x, t_game *s_game)
{
	free(s_game);
	exit(x);
}

int draw_block(int x, int y, t_game *s_game, void *img)
{
	char	q;
	
	if (img)
		return (mlx_put_image_to_window(s_game->mlx_p, s_game->w_p, img, x * 16, y * 16));
	q = ((char *)(findex(s_game->map, y)->content))[x];
	p("zz: %c, %d", q, s_game->key_map[q]);
	mlx_put_image_to_window(s_game->mlx_p, s_game->w_p, s_game->key_map[q], x * 16, y * 16);
	// p("draw_block: w<%d>, h<%d>\n", s_game->w, s_game->h);
	return (1);
}

char	*draw_all(t_game *s_game, int *xy)
{
	int		i;
	int		j;

	if (xy)
		return ((char *)(findex(s_game->map, xy[1] - 1)->content));
	i = 0;
	j = 0;
	while (i < s_game->y_len)
	{
		while (j < s_game->x_len)
		{
			draw_block(j, i, s_game, NULL);
			j++;
		}
		j = 0;
		i++;
	}
	draw_block(s_game->p[0], s_game->p[1], s_game, s_game->key_map['P']);
	return (0);
}

int	events(int k, struct s_game *s_game)
{
	if (k == 53)
		xit(0, s_game);
	if (k != 13 && k != 0 && k != 1 && k != 2)
		return (0);
	s_game->select = k;
	p("key<%d> ", k);
	update(s_game);
	return (0);
}

int	init1(t_game *s_game, char **c)
{
	struct s_read_map	s_read_map;
	t_pf				*pf;
	pf = malloc(sizeof(t_pf));
	pf->key_map[0] = 13;
	pf->key_map[1] = 0;
	pf->key_map[2] = 1;
	pf->key_map[3] = 2;

	s_read_map.s_game = s_game;
	s_game->colls = 0;
	s_read_map.end = 0;
	s_read_map.p_p = 0;
	s_read_map.exit_code = 0;
	s_read_map.count_E = 0;
	s_read_map.count_P = 0;
	s_game->my_colls = 0;
	s_game->end = 0;
	s_game->key_map[48] = mlx_xpm_file_to_image(s_game->mlx_p, "assets/bg.xpm", &s_game->w, &s_game->h);
	s_game->key_map[80] = mlx_xpm_file_to_image(s_game->mlx_p, "assets/ghasta.xpm", &s_game->w, &s_game->h);
	s_game->key_map[49] = mlx_xpm_file_to_image(s_game->mlx_p, "assets/wall.xpm", &s_game->w, &s_game->h);
	s_game->key_map[69] = mlx_xpm_file_to_image(s_game->mlx_p, "assets/exit_1.xpm", &s_game->w, &s_game->h);
	s_game->key_map[67] = mlx_xpm_file_to_image(s_game->mlx_p, "assets/main_c.xpm", &s_game->w, &s_game->h);
	s_game->set_wasd[13][0] = 0;
	s_game->set_wasd[13][1] = -1;
	s_game->set_wasd[0][0] = -1;
	s_game->set_wasd[0][1] = 0;
	s_game->set_wasd[1][0] = 0;
	s_game->set_wasd[1][1] = 1;
	s_game->set_wasd[2][0] = 1;
	s_game->set_wasd[2][1] = 0;
	s_read_map.exit_code = load_map(&s_read_map, c);
	if (s_read_map.exit_code)
	{
		p("error load map1: %d\n", s_read_map.exit_code);
		return (1);
	}
	draw_all(s_game, NULL);
	mlx_key_hook(s_game->w_p, &events, s_game);
	s_read_map.exit_code = validate_map(s_game, pf);
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
