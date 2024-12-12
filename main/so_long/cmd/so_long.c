/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 00:06:31 by ahbasara          #+#    #+#             */
/*   Updated: 2024/12/10 05:16:22 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include "mlx.h"
#include <stdlib.h>

static char const *const	g_err_str[] = {
[_E_0] = \
	_ERR_PREFIX "followed by an explicit error message of your choice.\n",
[_E_OPEN_MAP_FILE] = \
	_ERR_PREFIX "cannot open map descriptor file.\n",
[_E_MAP_EXT] = \
	_ERR_PREFIX "wrong map ext.\n",
[_E_ALLOCATION] = \
	_ERR_PREFIX "malloc error.\n",
[_E_END] = \
	_ERR_PREFIX "an unknown, undefined, unidentified error has been occured.\n",
[_E_MULTIMAP] = \
	_ERR_PREFIX "multiple maps in file.\n",
[_E_ROWDIFF] = \
	_ERR_PREFIX "row length differs.\n",
[_E_DUPCHAR] = \
	_ERR_PREFIX "duplicate character in map.\n",
[_E_COLLECTABLES] = \
	_ERR_PREFIX "no collectables in map.\n",
[_E_V_BORDER] = \
	_ERR_PREFIX "vertical border error.\n",
[_E_H_BORDER] = \
	_ERR_PREFIX "horizontal border error.\n",
[_E_INVALIDCH] = \
	_ERR_PREFIX "invalid character in map.\n",
[_E_GNL_NULL] = \
	_ERR_PREFIX "get_next_line returned NULL.\n",
[_E_SMALL_MAP] = \
	_ERR_PREFIX "map is too small.\n",
[_E_FLOODFILL] = \
	_ERR_PREFIX "flood fill error.\n",
[_E_ALLOC_MLX] = \
	_ERR_PREFIX "mlx allocation error.\n",
[_E_PLAYER] = \
	_ERR_PREFIX "player not found.\n",
[_E_EXIT] = \
	_ERR_PREFIX "exit not found.\n",
};

// void	load_map2(struct s_i *s_i, int *fd_map, char **c, t_game *s_g)
// {
// 	if (!*(c + 1) || !strnstr(*(c + 1), ".ber", xstrlen(*(c + 1))))
// 		abandonner(s_g, s_i, "ext not end with .ber\n", 0);
// 	*fd_map = open(*(c + 1), O_RDONLY);
// 	if (*fd_map < 3)
// 		abandonner(s_g, s_i, 0, errno);
// 	(*s_i).line = multi_get_line(*fd_map);
// 	s_i->line[xstrlen(s_i->line) - 1] = 0;
// 	(*s_i).oldlen = xstrlen((*s_i).line);
// 	if (check_y_border((*s_i).line))
// 		abandonner(s_g, s_i, "0y border err", 0);
// 	(*s_i).i = 1;
// 	printf("arstarst      %s\n", s_i->line);
// 	(*s_i).s_g->map = llnew(s_i->line);
// }

t_err	print_error(t_err err)
{
	ft_printf("%s", g_err_str[err]);
	return (err);
}

// void	print_map(t_map *map) {
// 	for (t_list *node = map->x; node != NULL; node = node->next) {
// 		ft_printf("--%s\n", node->content);
// 	}
// }

void	dispose_map(t_map *map)
{
	ft_lstclear(&map->x, free);
	ft_lstclear(&map->enemy, free);
}

void	dispose_game(t_game *game)
{
	int	text_idx;
	int	frame_idx;

	text_idx = 0;
	dispose_map(&game->map);
	while (text_idx < 6)
	{
		frame_idx = 0;
		while (frame_idx < FPS)
		{
			if (game->img[text_idx][frame_idx] != NULL)
				mlx_destroy_image(game->mlx, game->img[text_idx][frame_idx]);
			frame_idx++;
		}
		text_idx++;
	}
	mlx_destroy_window(game->mlx, game->win);
}

void	dispose_main(t_game *game)
{
	dispose_game(game);
	free(game->mlx);
}

// print movoment count to shell
int	main(int ac, char *av[])
{
	t_game *const	game = &(t_game){0};

	if (ac != 2)
		return (ft_printf("%susage: %s%s %s\n",
				RED, BLUE, av[0], YELLOW "<map>" RESET), 1);
	if (load_map(av[1], game))
		return (print_error(game->err));
	validate_map(game);
	if (game->err)
		return (dispose_map(&game->map), print_error(game->err));
	if (init_mlx(game))
		return (dispose_main(game), print_error(game->err));
	return (dispose_map(&game->map), game->err);
}

// void __attribute__((destructor))after_main()
// {
// 	// system("leaks so_long");
// 	// cout << "rst" << endl;
// 	// __lsan_do_leak_check();
// 	// __lsan_do_recoverable_leak_check();
// }
