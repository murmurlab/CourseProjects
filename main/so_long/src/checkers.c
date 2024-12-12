/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 03:02:16 by ahbasara          #+#    #+#             */
/*   Updated: 2024/12/10 05:04:44 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

int	check_ext(char const *path, char const *ext)
{
	const size_t	path_len = ft_strlen(path);
	const size_t	ext_len = ft_strlen(ext);

	return (
		ft_strncmp(path + (path_len - ext_len), ext, ext_len + 1)
	);
}

int	is_valid_char(unsigned int i, char *str, void *p)
{
	(void)(i);
	(void)(p);
	return (
		str[0] == '1' || \
		str[0] == 'P' || \
		str[0] == '0' || \
		str[0] == 'C' || \
		str[0] == 'E' || \
		str[0] == 'X'
	);
}

int	is_valid_char_v(unsigned int i, char *str, void *p)
{
	(void)(i);
	(void)(p);
	return (
		str[0] == '1'
	);
}

int	is_end(int fd)
{
	char	*line;

	line = NULL;
	while (free(line), 1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			return (1);
		if (line[0] != '\0')
			break ;
	}
	return (free(line), 0);
}

t_err	check_map(t_map_ctl *map_ctl)
{
	if (map_ctl->h < 3)
		return (map_ctl->err = _E_SMALL_MAP);
	if (map_ctl->colls < 1)
		return (map_ctl->err = _E_COLLECTABLES);
	if (map_ctl->count_p != 1)
		return (map_ctl->err = _E_PLAYER);
	if (map_ctl->count_e < 1)
		return (map_ctl->err = _E_EXIT);
	return (_E_0);
}
