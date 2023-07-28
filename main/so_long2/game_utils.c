#include "game.h"

int	check_lines\
(
	struct s_read_map *s_read_map
)
{
	if (*(s_read_map->line) != '1' || *(s_read_map->line + \
	(s_read_map->old_x_len - 2)) != '1')
		return (1);
	if (s_read_map->old_x_len != xstrlen(s_read_map->line))
	{
		if (!xstrchr(s_read_map->line, '\n'))
			s_read_map->end = 1;
		else
			return (2);
	}
	s_read_map->count_P += (short)strclen(s_read_map->line, 'P');
	s_read_map->count_E += (short)strclen(s_read_map->line, 'E');
	findex(s_read_map->s_game->map, (*s_read_map).i - 1)->content = \
	malloc(s_read_map->old_x_len);
	//p("%s", findex(s_read_map->s_game->map, (*s_read_map).i - 1)->content);
	if (s_read_map->count_E > 1 || s_read_map->count_P > 1)
		return (6);
	s_read_map->p_p = xstrchr(s_read_map->line, 'P'); // maybe not need player coords
	s_read_map->s_game->colls += (short)strclen(s_read_map->line, 'C');
	if (s_read_map->p_p)
	{
		*s_read_map->p_p = '0';
		s_read_map->s_game->p = malloc(2);
		s_read_map->s_game->p[0] = (s_read_map->p_p - s_read_map->line);
		s_read_map->s_game->p[1] = s_read_map->i - 1;
	}
	xstrlcpy(findex(s_read_map->s_game->map, (*s_read_map).i - 1)->content, \
	s_read_map->line, s_read_map->old_x_len + s_read_map->end);
	return (0);
}

int	check_y_border(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i])
	{
		if (line[i++] != '1')
			return (4);
	}
	return (0);
}

int	load_map(struct s_read_map *s_read_map, char **c)
{
	int		fd_map;

	fd_map = open(*(c + 1), O_RDONLY);
	(*s_read_map).line = multiRowRead(fd_map);
	(*s_read_map).old_x_len = xstrlen((*s_read_map).line); //first check_lines(s_read_map)
	if (check_y_border((*s_read_map).line))
		return (5);
	(*s_read_map).i = 1;
	(*s_read_map).s_game->map = llnew(0);
	while (1)
	{
		s_read_map->exit_code = check_lines(s_read_map);
		if (s_read_map->exit_code)
			return (s_read_map->exit_code);
		free((*s_read_map).line);
		(*s_read_map).old_x_len = xstrlen((*s_read_map).line);
		(*s_read_map).line = multiRowRead(fd_map);
		if (s_read_map->line)
		{
			(*s_read_map).i++;
			lladd(&s_read_map->s_game->map, llnew(0));
		}
		else
			break ;
	}
	s_read_map->s_game->y_len = s_read_map->i;
	
	if (check_y_border(llend(s_read_map->s_game->map)->content))
		return (7);
	free((*s_read_map).line);
	close(fd_map);
	return (0);
}

void iter(void *s)
{
	p("%s\n", s);
}
// struct arithmetic
t_around	wasd(struct s_game *s_game)
{
	t_around	wasd;

	wasd.w = (((char *)(findex(s_game->map, s_game->p[1] - 1)->content))[s_game->p[0]]);
	wasd.a = (((char *)(findex(s_game->map, s_game->p[1])->content))[s_game->p[0] - 1]);
	wasd.s = (((char *)(findex(s_game->map, s_game->p[1] + 1)->content))[s_game->p[0]]);
	wasd.d = (((char *)(findex(s_game->map, s_game->p[1])->content))[s_game->p[0] + 1]);
	wasd.o = (((char *)(findex(s_game->map, s_game->p[1])->content))[s_game->p[0]]);
	return(wasd);
}

int		update(t_game *s_game)
{
	t_around	wasd1;

	wasd1 = wasd(s_game);
	if (wasd1.w == 'E' && s_game->my_colls == s_game->colls)
			return (0);
	p("x:%d, y:%d ", s_game->p[0], s_game->p[1]);
	if (wasd1.w == 'C')
	{

	}
	draw_block(s_game->p[0] + s_game->wasd[s_game->select][0], s_game->p[1] + s_game->wasd[s_game->select][1], s_game, s_game->plyr);
	draw_block(s_game->p[0], s_game->p[1], s_game, NULL);
	s_game->p[1] += s_game->wasd[s_game->select][1];
	s_game->p[0] += s_game->wasd[s_game->select][0];
	// lliter(s_game->map, &iter);
}

int	move(char c, struct s_game *s_game)
{

	if (c == 'w' && (wasd1.w == 'C' && (s_game->my_colls++ || 1) || wasd1.w != '1'))
		update(s_game, 0, -1, wasd1);
	if (c == 'a' && (wasd1.a == 'C' && (s_game->my_colls++ || 1) || wasd1.a != '1'))
		update(s_game, -1, 0, wasd1);
	if (c == 's' && (wasd1.s == 'C' && (s_game->my_colls++ || 1) || wasd1.s != '1'))
		update(s_game, 0, 1, wasd1);
	if (c == 'd' && (wasd1.d == 'C' && (s_game->my_colls++ || 1) || wasd1.d != '1'))
		update(s_game, 1, 0, wasd1);
	return (0);
}

int	validate_map(struct s_game *s_game, char c)
{
	p("%d\n", s_game->x_len);
	p("%d\n", s_game->x_len);



	//path-finder

	if (wasd(s_game).w == 'E')
		return (1);
		;
	if (wasd(s_game).a == 'E')
		return (1);
		;
	if (wasd(s_game).s == 'E')
		return (1);
		;
	if (wasd(s_game).d == 'E')
		return (1);
		;

	
	t_list	*path;

	path = llnew(0);

	return (0);
}
