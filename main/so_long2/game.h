#ifndef GAME_H
# include <fcntl.h>
# include "./minilibx-linux/mlx.h"
# include "../murmurlibc/murmurlibc.h"

typedef struct s_obj
{
	int	x;
	int	y;
}		t_obj;

typedef struct s_game
{
	char	**map;
	char	**p;
	t_obj	*e;
}		t_game;

int	load_map(t_game *s_game, char **c);
int	init(t_game *s_game, char **c);

#endif