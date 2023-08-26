/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 22:56:49 by ahbasara          #+#    #+#             */
/*   Updated: 2023/08/25 22:56:49 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
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

# include <fcntl.h>
# include "../murmurlibc/murmurlibc.h"

typedef struct s_g
{
	int				loop;
	int				direction[2];
	char			set_wasd[W + 1][2];
	int				select;
	int				ct;
	char			*get_wasd[W + 1];
	void			*mlx_p;
	void			*w_p;
	int				wt;
	int				hh;
	int				key_arr[4];
	void			*key_map[81];
	t_list			*map;
	int				*p;
	int				y_len;
	int				x_len;
	short			colls;
	short			my_colls;
	t_list			*colls_xy;
	int				x_p[2];
	int				end;
}		t_game;

struct s_init
{
	int		count_e;
	int		count_p;
	char	*p_p;
	char	*x_p;
	int		old_x_len;
	char	*line;
	int		i;
	t_game	*s_g;
	int		end;
	int		exit_code;
};

typedef struct s_simulation
{
	int		i;
	int		e_flag;
	int		first;
	int		*p;
	t_list	*stack;
}		t_pf;

void	dell(void *p);
void	resolve_key(t_game *sgame);
void	render(t_game *s_g, t_pf *pf);
void	print_alter(t_list *tt);
void	check3(unsigned int i, char *ss, void *ptr);
void	print_map(t_game *s_g);
char	*draw_all(t_game *s_g, int y);
int		draw_block(int x, int y, t_game *s_g, void *img);
int		load_map(struct s_init *s_init, char **c);
int		init(t_game *s_g, char **c);
int		validate_map(struct s_g *s_g, t_pf *pf);
int		draw(int x, int y, void *pt, t_game *s_g);
int		move(char c, struct s_g *s_g);
void	wasd(struct s_g *s_g, int *xy, int a);
int		update(t_game *s_g);
int		xit(int x, t_game *s_g);
#endif
