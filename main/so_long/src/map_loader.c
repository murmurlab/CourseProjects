/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 01:13:45 by ahbasara          #+#    #+#             */
/*   Updated: 2024/12/10 04:51:03 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include <stdlib.h>
#include <stddef.h>
#include <fcntl.h>
#include <unistd.h>

t_err	check_char(t_map_ctl *map_ctl)
{
	map_ctl->count_p += ft_strclen(map_ctl->row, 'P');
	map_ctl->count_e += ft_strclen(map_ctl->row, 'E');
	if (map_ctl->count_p > 1 || map_ctl->count_e > 1)
		return (map_ctl->err = _E_DUPCHAR);
	map_ctl->ch_p = ft_strchr(map_ctl->row, 'P');
	map_ctl->ch_e = ft_strchr(map_ctl->row, 'E');
	return (_E_0);
}

t_err	check_line(t_map_ctl *map_ctl)
{
	if (map_ctl->prev_len != ft_strlen(map_ctl->row))
		return (map_ctl->err = _E_ROWDIFF);
	if (ft_strevery(map_ctl->row, is_valid_char, NULL))
		return (map_ctl->err = _E_INVALIDCH);
	if (*map_ctl->row != '1' || \
		*(map_ctl->row + (map_ctl->prev_len - 1)) != '1')
		return (map_ctl->err = _E_H_BORDER);
	if (check_char(map_ctl))
		return (map_ctl->err);
	if (ft_striter_error(map_ctl->row, &process_ch, map_ctl))
		return (map_ctl->err);
	if (map_ctl->ch_e != NULL)
	{
		map_ctl->exit.x = map_ctl->ch_e - map_ctl->row;
		map_ctl->exit.y = map_ctl->h - 1;
	}
	if (map_ctl->ch_p != NULL)
	{
		*map_ctl->ch_p = '0';
		map_ctl->player.x = (map_ctl->ch_p - map_ctl->row);
		map_ctl->player.y = map_ctl->h - 1;
	}
	return (_E_0);
}

char	*next_row(t_map_ctl *map_ctl)
{
	map_ctl->prev_len = ft_strlen(map_ctl->row);
	map_ctl->row = get_next_line(map_ctl->fd);
	if (map_ctl->row == NULL)
		return (NULL);
	map_ctl->h++;
	map_ctl->row[ft_strlen(map_ctl->row) - 1] = '\0';
	return (map_ctl->row);
}

t_err	read_map_fd(t_map_ctl *mapctl)
{
	if (next_row(mapctl) == NULL)
		return (mapctl->err = _E_GNL_NULL);
	if (ft_strevery(mapctl->row, is_valid_char_v, NULL))
		return (mapctl->err = _E_INVALIDCH);
	mapctl->tmp = ft_lstnew(mapctl->row);
	if (mapctl->tmp == NULL)
		return (mapctl->err = _E_ALLOCATION);
	while (ft_lstadd_back(&mapctl->x, mapctl->tmp), next_row(mapctl))
	{
		if (mapctl->row[0] == '\0')
			break ;
		if (check_line(mapctl))
			return (mapctl->err);
		mapctl->tmp = ft_lstnew(mapctl->row);
		if (mapctl->tmp == NULL)
			return (mapctl->err = _E_ALLOCATION);
	}
	if (mapctl->prev_len != ft_strlen(ft_lstlast(mapctl->x)->content))
		return (mapctl->err = _E_ROWDIFF);
	if (ft_strevery(ft_lstlast(mapctl->x)->content, is_valid_char_v, NULL))
		return (mapctl->err = _E_INVALIDCH);
	if (!is_end(mapctl->fd))
		return (mapctl->err = _E_MULTIMAP);
	return (_E_0);
}

t_err	load_map(char *path, t_game *game)
{
	t_map_ctl *const	map_ctl = &(t_map_ctl){0};

	map_ctl->row = "";
	if (check_ext(path, _EXT_BER))
		return (game->err = _E_MAP_EXT);
	map_ctl->fd = open(path, O_RDONLY);
	if (map_ctl->fd < 0)
		return (game->err = _E_OPEN_MAP_FILE);
	read_map_fd(map_ctl);
	free(map_ctl->row);
	map_ctl->row = NULL;
	close(map_ctl->fd);
	if (map_ctl->err)
		return (dispose_map_loader(map_ctl), game->err = map_ctl->err);
	if (check_map(map_ctl))
		return (dispose_map_loader(map_ctl), game->err = map_ctl->err);
	assign_map(&game->map, map_ctl);
	return (game->err = map_ctl->err);
}
