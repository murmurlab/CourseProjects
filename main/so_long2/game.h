#ifndef GAME_H
# if defined(__linux__)
	/* Linux. --------------------------------------------------- */
#  include "./minilibx-linux/mlx.h"
# elif defined(__APPLE__)
	/* OSX. --------------------------------------------------- */
#  include "./minilibx_opengl_20191021/mlx.h"
# endif

# include <fcntl.h>
# include "../murmurlibc/murmurlibc.h"

typedef struct s_game
{
	char			**map;
	char			*p;
	int				y_len;
	int				x_len;
	short			colls;
}		t_game;
struct s_read_map
{
	char	*p_e;
	char	*p_p;
	int		old_x_len;
	char	*line;
	int		i;
	t_game	*s_game;
};

int	load_map(struct s_read_map *s_read_map, char **c);
int	init(t_game *s_game, char **c);
int	validate_map(struct s_game *s_game);

#endif