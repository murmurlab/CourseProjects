#ifndef GAME_H
# if defined(__linux__)
	/* Linux. --------------------------------------------------- */
#  include "./minilibx-linux/mlx.h"
	/* WSL keycodes */
#  define W 119
#  define A 97
#  define S 115
#  define D 100
# elif defined(__APPLE__)
	/* OSX. --------------------------------------------------- */
#  include "./minilibx_opengl_20191021/mlx.h"
#  define W 13
#  define A 0
#  define S 1
#  define D 2
# endif

# define w
# define a
# define s
# define d
# include <fcntl.h>
# include "../murmurlibc/murmurlibc.h"

typedef struct s_game
{
	char			set_wasd[W+1][2];
	int				select;
	int				ct;
	char			*get_wasd[W+1];
	void			*mlx_p;
	void			*w_p;
	int				wt;
	int				hh;
	int				key_arr[4];
	void			*key_map[81];
	t_list			*map;
	char			*p;
	int				y_len;
	int				x_len;
	short			colls;
	short			my_colls;
	int				end;
}		t_game;

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

typedef struct s_simulation
{
	int		i;
	int		e_flag;
	t_list	*stack;
}		t_pf;


char	*draw_all(t_game *s_game, int y);
int 	draw_block(int x, int y, t_game *s_game, void *img);
int		load_map(struct s_read_map *s_read_map, char **c);
int		init(t_game *s_game, char **c);
int		validate_map(struct s_game *s_game, t_pf *pf);
int 	draw(int x, int y, void *pt, t_game *s_game);
int		move(char c, struct s_game *s_game);
void	wasd(struct s_game *s_game, char *xy, int a);
int		update(t_game *s_game);
int		xit(int x, t_game *s_game);
#endif