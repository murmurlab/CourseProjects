#include "game.h"

int	check_lines\
(
	struct s_read_map *s_read_map
)
{
	s_read_map->s_game->p = malloc(2);
	// count 'c'
	// check double 'e' 'p'
	if (*(s_read_map->line + 0) != '1' || *(s_read_map->line + \
	(s_read_map->old_x_len - 2)) != '1')
		return (1);
	if (s_read_map->old_x_len != xstrlen(s_read_map->line))
	{
		if ((s_read_map->s_game->y_len == s_read_map->i) \
		&& (xstrlen(s_read_map->line) == (s_read_map->old_x_len - 1)))
			;
		else
		{
			return (1);
		}
	}
	s_read_map->s_game->map[(*s_read_map).i - 1] = \
	malloc(s_read_map->old_x_len);
	xstrlcpy(s_read_map->s_game->map[(*s_read_map).i - 1], \
	s_read_map->line, s_read_map->old_x_len);
	s_read_map->p_e = xstrchr(s_read_map->line, 'E');
	s_read_map->p_p = xstrchr(s_read_map->line, 'P');
	if (s_read_map->p_e)
		;
	return (0);
}

int	get_y_len(char *fname)
{
	int		fd_map;
	int		y;
	char	*temporal;

	y = 0;
	fd_map = open(fname, O_RDONLY);
	temporal = multiRowRead(fd_map);
	while (temporal)
	{
		free(temporal);
		temporal = multiRowRead(fd_map);
		y++;
	}
	close(fd_map);
	return (y);
}

int	check_y_border(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i])
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
	(*(*s_read_map).s_game).x_len = s_read_map->old_x_len - 1;
	(*(*s_read_map).s_game).y_len = get_y_len(*(c + 1));
	if (check_y_border((*s_read_map).line))
		return (1);
	(*s_read_map).i = 1;
	(*s_read_map).s_game->map = \
	(char **)malloc((*s_read_map).s_game->y_len * sizeof(char *));
	while (1)
	{
		if (check_lines(s_read_map))
			return (1);
		(*s_read_map).old_x_len = xstrlen((*s_read_map).line);
		if ((*s_read_map).s_game->y_len > (*s_read_map).i)
		{
			free((*s_read_map).line);
			(*s_read_map).line = multiRowRead(fd_map);
		}
		else
			break ;
		(*s_read_map).i++;
	}
	if (check_y_border((*s_read_map).line))
		return (1);
	free((*s_read_map).line);
	close(fd_map);
	return (0);
}

// struct arithmetic
int	validate_map(struct s_game *s_game)
{
	int	i;

	i = 0;
	while (i < s_game->y_len)
	{
		p("%s\n", s_game->map[i++]);
	}
	p("%d\n", s_game->x_len);
	p("%d\n", s_game->x_len);
	return (0);
}
