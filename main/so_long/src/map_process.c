/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 03:04:43 by ahbasara          #+#    #+#             */
/*   Updated: 2024/12/10 03:16:12 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

void	assign_map(t_map *map, t_map_ctl *map_ctl)
{
	map->h = map_ctl->h;
	map->w = ft_strlen(map_ctl->x->content);
	map->enemy = map_ctl->enemy;
	map->colls = map_ctl->colls;
	map->player = map_ctl->player;
	map->exit = map_ctl->exit;
	map->x = map_ctl->x;
	map->err = map_ctl->err;
}

int	process_ch(unsigned int i, char *ss, void *ptr)
{
	t_map_ctl *const	map_ctl = ptr;
	t_point				*point;
	t_list				*tmp;

	if (ss[0] == 'X')
	{
		point = malloc(sizeof(t_point [1]));
		if (point == NULL)
			return (map_ctl->err = _E_ALLOCATION);
		tmp = ft_lstnew(point);
		if (tmp == NULL)
			return (free(point), map_ctl->err = _E_ALLOCATION);
		ft_lstadd_front(&map_ctl->enemy, tmp);
		point->x = i;
		point->y = map_ctl->h - 1;
		ss[0] = '0';
	}
	else if (ss[0] == 'C')
		map_ctl->colls++;
	return (0);
}
