#include "game.h"

int	check_map(char *line, size_t *x_len, size_t *y_len, t_game *s_game);

int	get_y_len(char *fname)
{
	int	fd_map;
	int	y;

	fd_map = open(fname, O_RDONLY);
	while (multiRowRead(fd_map))
		y++;
	close(fd_map);
	return (y);
}

int	load_map(t_game *s_game, char **c)
{
	int		fd_map;
	char	*line;
	size_t	x_len;
	size_t	y_len;

	fd_map = open(*(c + 1), O_RDONLY);
	line = multiRowRead(fd_map);
	y_len = get_y_len(*(c + 1));
	x_len = xstrlen(line);
	while (line[y_len] != '\n')
	{
		if (line[y_len++] != '1')
			return (1);
	}
	while (line)
	{
		if (check_map(line, &x_len, &y_len, s_game))
			return (1);
		x_len = xstrlen(line);
		line = multiRowRead(fd_map);
	}
	close(fd_map);
	return (0);
}

int	check_map(char *line, size_t *x_len, size_t *y_len, t_game *s_game)
{
	if (*(line + 0) != '1' || *(line + (*x_len - 2)) != '1')
		return (1);
	if (*x_len != xstrlen(line))
		return (1);
	xstrlcpy(s_game->map[*y_len - 1], line, *x_len);
	return (0);
}

