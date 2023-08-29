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

int	check_lines(struct s_i *s_i)
{
	if (*(s_i->line) != '1' || *(s_i->line + (s_i->oldlen - 2)) != '1')
		return (1);
	if (s_i->oldlen != xstrlen(s_i->line))
	{
		if (!xstrchr(s_i->line, '\n'))
			s_i->end = 1;
		else
			return (2);
	}
	s_i->count_p += (short)strclen(s_i->line, 'P');
	s_i->count_e += (short)strclen(s_i->line, 'E');
	findex(s_i->s_g->map, (*s_i).i - 1)->content = malloc(s_i->oldlen);
	if (s_i->count_e > 1 || s_i->count_p > 1)
		return (6);
	check_lines2(s_i);
	llend(s_i->s_g->map)->content = s_i->line;
	return (0);
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

int	load_map(struct s_i *s_i, char **c, t_game *s_g)
{
	int		fd_map;

	load_map2(s_i, &fd_map, c, s_g);
	while (1)
	{
		s_i->exit_code = check_lines(s_i);
		if (s_i->exit_code)
			return (s_i->exit_code);
		(*s_i).oldlen = xstrlen((*s_i).line);
		(*s_i).line = multiRowRead(fd_map);
		if (s_i->line)
		{
			(*s_i).i++;
			lladd(&s_i->s_g->map, llnew(0));
		}
		else
			break ;
	}
	s_i->s_g->y_len = s_i->i;
	s_i->s_g->x_len = s_i->oldlen;
	if (check_y_border(llend(s_i->s_g->map)->content))
		return (7);
	free((*s_i).line);
	close(fd_map);
	return (0);
}

int	update(t_game *s_g)
{
	// print_map(s_g);
	// animate(s_g);
	if (s_g->select == -1)
		return (0);
	wasd(s_g, s_g->p, 0, 0);
	if (s_g->get[s_g->select][0] == 'E' && s_g->my_colls == s_g->colls)
		render(s_g, 0, 0);
	// if (s_g->get[s_g->select][0] == 'X')
		// render(s_g, 0, 0);
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
		((struct s_i *)ptr)->s_g->colls_xy->content = malloc(sizeof(int) * 2);
		((int *)(((struct s_i *)ptr)->s_g->colls_xy->content))[1] = ((struct \
				s_i *)ptr)->i - 1;
		((int *)(((struct s_i *)ptr)->s_g->colls_xy->content))[0] = i;
	}
	if (ss[0] == 'X')
	{
		ss[0] = '0';
		llprepend(&((struct s_i *)ptr)->s_g->enemy_xy, llnew(0));
		((struct s_i *)ptr)->s_g->enemy_xy->content = malloc(sizeof(int) * 3);
		((int *)(((struct s_i *)ptr)->s_g->enemy_xy->content))[1] = ((struct \
				s_i *)ptr)->i - 1;
		((int *)(((struct s_i *)ptr)->s_g->enemy_xy->content))[0] = i;
		((int *)(((struct s_i *)ptr)->s_g->enemy_xy->content))[2] = 1;
	}
}
