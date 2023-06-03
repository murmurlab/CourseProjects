#include "game.h"

void	init(t_game *s_game, char **c)
{
	load_map(s_game, c);
}

int	main(int c, char *v[])
{
	void	*mlx_p;
	void	*w_p;
	t_game	s_game;

	mlx_p = mlx_init();
	w_p = mlx_new_window(mlx_p, 500, 500, "game");
	init(&s_game, v);
	mlx_loop(mlx_p);
}
