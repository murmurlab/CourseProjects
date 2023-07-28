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
	char			wasd[13][2];
	char			select;
	void			*mlx_p;
	void			*w_p;
	int				w;
	int				h;
	void			*bcgr;
	void			*plyr;
	void			*wall;
	void			*exit;
	void			*coll;
	t_list			*map;
	char			*p;
	int				y_len;
	int				x_len;
	short			colls;
	short			my_colls;
	int				end;
	t_list			path;
}		t_game;

typedef struct s_around
{
	char	w;
	char	a;
	char	s;
	char	d;
	char	o;
}		t_around;
struct s_read_map
{
	int		count_E;
	int		count_P;
	char	*p_p;
	int		old_x_len;
	char	*line;
	int		i;
	t_game	*s_game;
	int		end;
	int		exit_code;
};

int draw_block(int x, int y, t_game *s_game, void *img);
int	load_map(struct s_read_map *s_read_map, char **c);
int	init(t_game *s_game, char **c);
int	validate_map(struct s_game *s_game, char c);
int draw(int x, int y, void *pt, t_game *s_game);
int	move(char c, struct s_game *s_game);

#endif