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

# include "../murmurlibc/murmurlibc.h"

typedef struct s_simulation
{
	int		i;
	int		e_flag;
	int		first;
	int		*p;
	t_list	*stack;
}		t_pf;

typedef struct s_g
{
	t_pf			*pf;
	void			*p_anim[2];
	int				step;
	int				loop;
	int				direction[2];
	char			set[W + 1][2];
	int				select;
	int				ct;
	char			*get[W + 1];
	void			*m_p;
	void			*w_p;
	int				g;
	int				y;
	int				karr[4];
	void			*km[82];
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

struct s_i
{
	int		f_line;
	int		count_e;
	int		count_p;
	char	*p_p;
	char	*x_p;
	int		oldlen;
	char	*line;
	int		i;
	t_game	*s_g;
	int		end;
	int		exit_code;
};

void	quit(void *ptr);
int		check_lines(struct s_i *s_i);
void	forbidden_ch(unsigned int i, char *str, void *p);
void	animate_player(t_game *s_g);
void	step(t_game *s_g);
void	check_lines2(struct s_i *s_i);
void	abandonner(t_game *s_g, struct s_i *s_i, char *str, int no);
void	abandonner2(t_game *s_g);
void	load_map3(struct s_i *s_i, int *fd_map);
void	load_map2(struct s_i *s_i, int *fd_map, char **c, t_game *s_g);
void	validate4(t_pf *pf, t_game *s_g);
int		validate3(t_pf *pf, t_game *s_g, char **pointer1);
void	validate2(t_pf *pf, t_list *tmp, t_game *s_g);
void	init3(t_game *s_g);
void	resolve_key(t_game *sgame);
int		events_d(int k, void *rr);
int		loop(void *rr);
int		events_u(int k, struct s_g *s_g);
void	resolve_key(t_game *sgame);
void	render(t_game *s_g, t_pf *pf);
void	print_alter(t_list *tt);
void	check3(unsigned int i, char *ss, void *ptr);
void	print_map(t_game *s_g);
char	*putall(t_game *s_g, int y);
int		draw_block(int x, int y, t_game *s_g);
int		check_y_border(char *line);
int		draw_b(int x, int y, t_game *s_g, void *img);
void	load_map(struct s_i *s_i, char **c, t_game *s_g);
void	init1(t_game *s_g, char **c);
void	validate_map(struct s_g *s_g, t_pf *pf);
int		draw(int x, int y, void *pt, t_game *s_g);
int		move(char c, struct s_g *s_g);
void	wasd(struct s_g *s_g, int *xy, int a, char ch);
int		update(t_game *s_g);
int		xit(t_game *s_g, t_pf *pf, int aa);
int		init2(t_game *s_g, char **c, t_pf *pf, struct s_i *s_i);

#endif
