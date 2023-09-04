/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 22:56:40 by ahbasara          #+#    #+#             */
/*   Updated: 2023/08/25 22:56:40 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

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

void	load_map3(struct s_i *s_i, int *fd_map)
{
	s_i->s_g->y_len = s_i->i;
	s_i->s_g->x_len = s_i->oldlen;
	if (check_y_border(llend(s_i->s_g->map)->content))
		abandonner(s_i->s_g, s_i, "end y border err", 0);
	freedom((void **)&(*s_i).line);
	close(*fd_map);
}

void	load_map(struct s_i *s_i, char **c, t_game *s_g)
{
	int		fd_map;

	load_map2(s_i, &fd_map, c, s_g);
	while (1)
	{
		s_i->exit_code = check_lines(s_i);
		if (s_i->exit_code)
			abandonner(s_g, s_i, "bad line", 0);
		(*s_i).oldlen = xstrlen((*s_i).line);
		(*s_i).line = multi_get_line(fd_map);
		if (s_i->line)
		{
			s_i->line[s_i->oldlen] = 0;
			(*s_i).i++;
			lladd(&s_i->s_g->map, llnew(0));
		}
		else
			break ;
	}
	if (s_g->colls < 1)
		abandonner(s_g, s_i, "0 colls", 0);
	load_map3(s_i, &fd_map);
}

int	update(t_game *s_g)
{
	if (s_g->select == -1)
		return (0);
	wasd(s_g, s_g->p, 0, 0);
	if (s_g->get[s_g->select][0] == 'E' && s_g->my_colls == s_g->colls)
		abandonner(s_g, 0, "finish", 0);
	if (s_g->get[s_g->select][0] == 'C')
	{
		*s_g->get[s_g->select] = '0';
		wasd(s_g, s_g->p, 1, 'P');
		s_g->my_colls++;
		step(s_g);
	}
	else if (s_g->get[s_g->select][0] != '1')
	{
		step(s_g);
		wasd(s_g, s_g->p, 1, 'P');
	}
	animate_player(s_g);
	p("x:%d, y:%d ", s_g->p[0], s_g->p[1]);
	return (1);
}

void	check3(unsigned int i, char *ss, void *ptr)
{
	if (ss[0] == 'C')
	{
		llprepend(&((struct s_i *)ptr)->s_g->colls_xy, llnew(0));
		((struct s_i *)ptr)->s_g->colls_xy->content = callocate(sizeof(int), 2);
		((int *)(((struct s_i *)ptr)->s_g->colls_xy->content))[1] = ((struct \
				s_i *)ptr)->i - 1;
		((int *)(((struct s_i *)ptr)->s_g->colls_xy->content))[0] = i;
	}
}
