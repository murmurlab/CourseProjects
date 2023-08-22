#include "game.h"
#include <signal.h>

int	xit(int x, t_game *s_game)
{
	free(s_game);
	exit(x);
}

void	print_map(t_game *s_game)
{
	int	i;

	i = 0;
	while (i < s_game->y_len)
		p("%s", draw_all(s_game, i++));
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

char	*draw_all(t_game *s_game, int y)
{
	int		i;
	int		j;

	if (y)
		return ((char *)(findex(s_game->map, y)->content));
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
	p("key<%d> ", k);
	if (k == 53 || k == 65307)
		xit(0, s_game);
	if (k != W && k != A && k != S && k != D)
		return (0);
	s_game->select = k;
	update(s_game);
	return (0);
}

int	init1(t_game *s_game, char **c)
{
	struct s_read_map	s_read_map;
	t_pf				*pf;
	pf = malloc(sizeof(t_pf));
	pf->p = malloc(2 * sizeof(int));
	s_read_map.s_game = s_game;
	s_game->colls = 0;
	s_read_map.end = 0;
	s_read_map.p_p = 0;
	s_read_map.exit_code = 0;
	s_read_map.count_E = 0;
	s_read_map.count_P = 0;
	s_game->my_colls = 0;
	s_game->end = 0;
	s_game->key_map[48] = mlx_xpm_file_to_image(s_game->mlx_p, "assets/bg.xpm", &s_game->wt, &s_game->hh);
	s_game->key_map[80] = mlx_xpm_file_to_image(s_game->mlx_p, "assets/ghasta.xpm", &s_game->wt, &s_game->hh);
	s_game->key_map[49] = mlx_xpm_file_to_image(s_game->mlx_p, "assets/wall.xpm", &s_game->wt, &s_game->hh);
	s_game->key_map[69] = mlx_xpm_file_to_image(s_game->mlx_p, "assets/exit_1.xpm", &s_game->wt, &s_game->hh);
	s_game->key_map[67] = mlx_xpm_file_to_image(s_game->mlx_p, "assets/main_c.xpm", &s_game->wt, &s_game->hh);
	s_game->key_map[35] = mlx_xpm_file_to_image(s_game->mlx_p, "assets/wall.xpm", &s_game->wt, &s_game->hh);
	s_game->set_wasd[W][0] = 0;
	s_game->set_wasd[W][1] = -1;
	s_game->set_wasd[A][0] = -1;
	s_game->set_wasd[A][1] = 0;
	s_game->set_wasd[S][0] = 0;
	s_game->set_wasd[S][1] = 1;
	s_game->set_wasd[D][0] = 1;
	s_game->set_wasd[D][1] = 0;
	s_game->key_arr[0] = W;
	s_game->key_arr[1] = A;
	s_game->key_arr[2] = S;
	s_game->key_arr[3] = D;
	pf->e_flag = 0;
	s_read_map.exit_code = load_map(&s_read_map, c);
	p("asd2");
	if (s_read_map.exit_code)
	{
		p("error load map1: %d\n", s_read_map.exit_code);
		return (1);
	}
	p("asd5");
	s_game->w_p = mlx_new_window(s_game->mlx_p, s_game->hh * s_game->x_len, s_game->wt * s_game->y_len, "game");
	p("asd444444444444444444");
	draw_all(s_game, 0);
	p("asd3");
	s_read_map.exit_code = validate_map(s_game, pf);
	mlx_key_hook(s_game->w_p, &events, s_game);
	p("asd");
	if (s_read_map.exit_code)
	{
		p("error load map: %d\n", s_read_map.exit_code);
		return (1);
	}
	return (0);
}

int	main(int c, char *v[])
{
	t_game	*s_game;
	int		*asd;

	asd = (int a[22]){2};
	s_game = malloc(sizeof(t_game));
	p("BUFFER_SIZE: %d\n", BUFFER_SIZE);
	s_game->mlx_p = mlx_init();
	p("asd1");
	if (init1(s_game, v))
		return (1);
	mlx_loop(s_game->mlx_p);
}
