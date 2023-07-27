#include "game.h"
#include <signal.h>

int	init(t_game *s_game, char **c)
{
	struct s_read_map	s_read_map;

	s_read_map.s_game = s_game;
	s_game->colls = 0;
	s_read_map.end = 0;
	s_read_map.p_p = 0;
	s_read_map.exit_code = 0;
	s_read_map.count_E = 0;
	s_read_map.count_P = 0;
	s_read_map.exit_code = load_map(&s_read_map, c);
	if (s_read_map.exit_code)
	{
		p("error load map: %d\n", s_read_map.exit_code);
		return (1);
	}
	s_read_map.exit_code = validate_map(s_game);
	if (s_read_map.exit_code)
	{
		p("error load map: %d\n", s_read_map.exit_code);
		return (1);
	}
	return (0);
}

int	main(int c, char *v[])
{
	void				*mlx_p;
	void				*w_p;
	t_game				s_game;

	p("BUFFER_SIZE: %d\n", BUFFER_SIZE);
	mlx_p = mlx_init();
	w_p = mlx_new_window(mlx_p, 500, 500, "game");
	if (init(&s_game, v))
		return (1);
	mlx_loop(mlx_p);
}
