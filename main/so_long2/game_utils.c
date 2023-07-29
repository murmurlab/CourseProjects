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
		(*s_read_map).old_x_len = xstrlen((*s_read_map).line);
		free((*s_read_map).line);
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
	s_read_map->s_game->x_len = s_read_map->old_x_len;
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
void	wasd(struct s_game *s_game, char *xy, int a)
{
	if (a)
	{
		draw_block(xy[0] + s_game->set_wasd[s_game->select][0], xy[1] + s_game->set_wasd[s_game->select][1], s_game, s_game->key_map['P']);
		draw_block(xy[0], xy[1], s_game, NULL);
		xy[1] += s_game->set_wasd[s_game->select][1];
		xy[0] += s_game->set_wasd[s_game->select][0];
		return ;
	}
	s_game->get_wasd[13] = (((char *)(findex(s_game->map, xy[1] - 1)->content)) + xy[0]);
	s_game->get_wasd[0] = (((char *)(findex(s_game->map, xy[1])->content)) + (xy[0] - 1));
	s_game->get_wasd[1] = (((char *)(findex(s_game->map, xy[1] + 1)->content)) + xy[0]);
	s_game->get_wasd[2] = (((char *)(findex(s_game->map, xy[1])->content)) + (xy[0] + 1));
	s_game->get_wasd[3] = (((char *)(findex(s_game->map, xy[1])->content)) + xy[0]);
}

int		update(t_game *s_game)
{
	wasd(s_game, s_game->p, 0);
	if (s_game->get_wasd[s_game->select][0] == 'E' && s_game->my_colls == s_game->colls)
			exit(0);
	if (s_game->get_wasd[s_game->select][0] == 'C')
	{
		*s_game->get_wasd[s_game->select] = '0';
		wasd(s_game, s_game->p, 1);
		// lliter(s_game->map, &iter);
		s_game->my_colls++;
	}
	else if(s_game->get_wasd[s_game->select][0] != '1')
		wasd(s_game, s_game->p, 1);
	p("x:%d, y:%d ", s_game->p[0], s_game->p[1]);
	return (1);
}

int	validate_map(struct s_game *s_game, t_pf *pf)
{
	return (0);
	// p("%d\n", s_game->x_len);
	// p("%d\n", s_game->x_len);

	char xy[2];

	pf->i = 0;
	xy[0] = s_game->p[0];
	xy[1] = s_game->p[1];
	//path-finder
	pf->path = ll4new(0);


	while (1)
	{
		wasd(s_game, xy, 0);

		while (pf->i == 4)
		{			
			if (s_game->get_wasd[pf->key_map[pf->i]][0] == 'E' && (s_game->my_colls == s_game->colls))
			{
				pf->flag = 1;
				break ;
			}
			
			pf->i++;
		}
		

	}
	if (s_game->get_wasd[s_game->select][0] == 'E')
		return (1);
		;
	if (s_game->get_wasd[s_game->select][0] == 'E')
		return (1);
		;
	if (s_game->get_wasd[s_game->select][0] == 'E')
		return (1);
		;
	if (s_game->get_wasd[s_game->select][0] == 'E')
		return (1);
		;
	s_game->my_colls = 0;
	return (0);
}
