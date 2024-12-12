/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 08:01:28 by ahbasara          #+#    #+#             */
/*   Updated: 2024/12/10 03:48:46 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include <unistd.h>

void	*ft_strdup_void(void *s)
{
	return (ft_strdup(s));
}

void	*ft_memdup(void *content)
{
	t_point *const	tmp = malloc(sizeof(t_point));

	if (tmp == NULL)
		return (NULL);
	*tmp = *(t_point *)content;
	return (tmp);
}

char	*get_point(t_point p, t_list *x)
{
	return (((char *)findex(x, p.y)->content) + p.x);
}

int	flood_fill(t_map *map, t_point p)
{
	char *const	point = get_point(p, map->x);

	if (point[0] == '1')
		return (0);
	if (point[0] == 'E')
	{
		if (map->colls == 0)
			return (1);
		map->has_exit = 1;
	}
	else if (point[0] == 'C')
	{
		map->colls--;
		if (map->colls == 0 && map->has_exit)
			return (1);
	}
	point[0] = '1';
	return (
		flood_fill(map, (t_point){p.x + 1, p.y}) ||
		flood_fill(map, (t_point){p.x - 1, p.y}) ||
		flood_fill(map, (t_point){p.x, p.y + 1}) ||
		flood_fill(map, (t_point){p.x, p.y - 1})
	);
}

t_err	validate_map(t_game *game)
{
	t_map	map;

	game->err = _E_0;
	map = game->map;
	map.x = ft_lstmap(map.x, ft_strdup_void, free);
	if (map.x == NULL)
		return (game->err = _E_ALLOCATION);
	map.enemy = ft_lstmap(map.enemy, ft_memdup, free);
	map.validated = flood_fill(&map, map.player);
	if (!map.validated)
		game->err = _E_FLOODFILL;
	dispose_map(&map);
	return (game->err);
}
