/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 00:26:15 by ahbasara          #+#    #+#             */
/*   Updated: 2024/12/10 05:04:55 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// # if defined(__linux__)
/* Linux. --------------------------------------------------- */

// # elif defined(__APPLE__)
/* OSX. --------------------------------------------------- */

// # endif

// #include <stdio.h>
# include <libft.h>

/**
 * @brief 
 * • open, close, read, write,
 *   malloc, free, perror,
 *   strerror, exit
 * • All functions of the math
 *   library (-lm compiler option,
 *   man man 3 math)
 * • All functions of the MiniLibX
 * • ft_printf and any equivalent
 *   YOU coded
 */

# define RES				64

# define RED				"\x1B[31m"
# define GREEN				"\x1B[32m"
# define YELLOW				"\x1B[33m"
# define BLUE				"\x1B[34m"
# define RESET				"\x1B[0m"

# define _ERR_PREFIX		"Error\n"

# define _EXT_BER			".ber"
# define _EXT_XPM			".xpm"

# define FPS				6

typedef enum e_err
{
	_E_0,
	_E_ALLOCATION,
	_E_SMALL_MAP,
	_E_MULTIMAP,
	_E_ROWDIFF,
	_E_DUPCHAR,
	_E_COLLECTABLES,
	_E_V_BORDER,
	_E_FLOODFILL,
	_E_H_BORDER,
	_E_INVALIDCH,
	_E_GNL_NULL,
	_E_MAP_EXT,
	_E_OPEN_MAP_FILE,
	_E_ALLOC_MLX,
	_E_PLAYER,
	_E_EXIT,
	_E_END,
}	t_err;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_map
{
	t_err			err;
	t_list			*x;
	int				h;
	int				w;
	t_list			*enemy;
	size_t			colls;
	t_point			player;
	t_point			exit;
	int				has_exit;
	int				validated;
	int				movoment;
}	t_map;

typedef struct s_game
{
	t_err	err;
	void	*mlx;
	void	*win;
	int		frame;
	int		tick;
	void	*(img[6])[FPS];
	t_point	compansate;
	int		keys[280];
	t_map	map;
}	t_game;

typedef struct s_map_control
{
	t_list			*tmp;
	int				fd;
	char			*row;
	size_t			prev_len;
	t_err			err;
	size_t			count_p;
	size_t			count_e;
	t_list			*x;
	size_t			h;
	t_list			*enemy;
	size_t			colls;
	char			*ch_p;
	char			*ch_e;
	t_point			player;
	t_point			exit;
}	t_map_ctl;

void	dispose_map_loader(t_map_ctl *map_ctl);
int		loop_hook(void *param);
int		key_up(int keycode, t_game *game);
int		key_down(int keycode, t_game *game);
t_err	open_textures(t_game *game);
void	key_loop(t_game *game);
void	render_map(t_game *game);
int		reverse_key(int keycode);
t_point	calculate_new_position(t_point *point, t_point unit_vector);
int		enemy_coll(t_game *game, t_point new_pos);
int		exit_game(t_game *game);
void	move_enemy(t_game *game);
void	move(t_game *game, t_point unit_vector);
void	assign_map(t_map *map, t_map_ctl *map_ctl);
int		process_ch(unsigned int i, char *ss, void *ptr);
int		is_end(int fd);
t_err	check_map(t_map_ctl *map_ctl);
int		check_ext(char const *path, char const *ext);
int		is_valid_char(unsigned int i, char *str, void *p);
int		is_valid_char_v(unsigned int i, char *str, void *p);
void	dispose_game(t_game *game);
t_err	load_map(char *path, t_game *game);
t_err	validate_map(t_game *game);
t_err	init_mlx(t_game *game);
t_list	*findex(t_list *lst, int idx);

void	print_map(t_map *game);
void	dispose_map(t_map *map);

size_t	ft_strclen(const char *s, char c);
int		ft_strsome(char *s, int (*f)(unsigned int, char *, void *), void *pass);
int		ft_strevery(char *s,
			int (*f)(unsigned int, char *, void *), void *pass);
int		ft_striter_error(char *s,
			int (*f)(unsigned int, char*, void *), void *pp);

// # define stringify(str) stringify_(str)
// # define stringify_(str) #str
// # define ft_size(type, variable) sizeof(variable) / sizeof(type)

// #include <sanitizer/lsan_interface.h>

// void __attribute__((destructor))after_main()
// {
// 	// system("leaks so_long");
// 	// cout << "rst" << endl;
// 	// __lsan_do_leak_check();
// 	// __lsan_do_recoverable_leak_check();
// }

#endif // SO_LONG_H
