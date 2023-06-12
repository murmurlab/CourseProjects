#include "game.h"

int	init(t_game *s_game, char **c)
{
	struct s_read_map	s_read_map;

	s_read_map.s_game = s_game;
	if (load_map(&s_read_map, c))
	{
		p("error load map\n");
		return (1);
	}
	return (0);
}

int	main(int c, char *v[])
{
	void				*mlx_p;
	void				*w_p;
	t_game				s_game;

	mlx_p = mlx_init();
	w_p = mlx_new_window(mlx_p, 500, 500, "game");
	if (init(&s_game, v))
		return (1);
	mlx_loop(mlx_p);
}
