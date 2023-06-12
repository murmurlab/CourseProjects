#include "game.h"

int	check_lines\
(
	struct s_read_map *s_read_map
)
{
	if (*(s_read_map->line + 0) != '1' || *(s_read_map->line + \
	(s_read_map->old_x_len - 2)) != '1')
		return (1);
	if (s_read_map->old_x_len != xstrlen(s_read_map->line))
	{
		if ((s_read_map->y_len == s_read_map->i) \
		&& (xstrlen(s_read_map->line) == (s_read_map->old_x_len - 1)))
			;
		else
		{
			return (1);
		}
	}
	s_read_map->s_game->map[s_read_map->y_len - 1] = \
	malloc(s_read_map->old_x_len);
	xstrlcpy(s_read_map->s_game->map[s_read_map->y_len - 1], \
	s_read_map->line, s_read_map->old_x_len);
	return (0);
}

int	get_y_len(char *fname)
{
	int	fd_map;
	int	y;

	y = 0;
	fd_map = open(fname, O_RDONLY);
	while (multiRowRead(fd_map))
		y++;
	close(fd_map);
	return (y);
}

int	check_y_border(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n')
	{
		if (line[i++] != '1')
			return (1);
	}
	return (0);
}

int	load_map(struct s_read_map *s_read_map, char **c)
{
	int		fd_map;

	fd_map = open(*(c + 1), O_RDONLY);
	(*s_read_map).line = multiRowRead(fd_map);
	(*s_read_map).old_x_len = xstrlen((*s_read_map).line);
	(*s_read_map).y_len = get_y_len(*(c + 1));
	check_y_border((*s_read_map).line);
	(*s_read_map).i = 1;
	(*s_read_map).s_game->map = \
	(char *)malloc((*s_read_map).y_len * sizeof(char *));
	p("%p", (*s_read_map).s_game->map[0]);
	while (1)
	{
		if (check_lines(s_read_map))
			return (1);
		(*s_read_map).old_x_len = xstrlen((*s_read_map).line);
		if ((*s_read_map).y_len > (*s_read_map).i)
			(*s_read_map).line = multiRowRead(fd_map);
		else
			break ;
		(*s_read_map).i++;
	}
	check_y_border((*s_read_map).line);
	close(fd_map);
	return (0);
}
