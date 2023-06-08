#include "game.h"

int	check_map(char *line, size_t *x_len, size_t *y_len);

void	load_map(t_game *s_game, char **c)
{
	int		fd_map;
	char	*line;
	size_t	x_len;
	size_t	y_len;

	fd_map = open(*(c + 1), O_RDONLY);
	line = multiRowRead(fd_map);
	x_len = xstrlen(line);
	y_len = 1;
	while (*line)
	{
		if (*(line++) != 1)
			return (1);
	}
	while (line)
	{
		check_map(line, &x_len, &y_len);
		x_len = xstrlen(line);
		line = multiRowRead(fd_map);
	}
}

int	check_map(char *line, size_t *x_len, size_t *y_len)
{
	if (*(line + 0) != '1' || *(line + (*x_len - 1)) != '1')
		return (1);
	if (*x_len != xstrlen(line))
		return (1);
}
