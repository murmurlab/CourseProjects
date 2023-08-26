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

int	check_lines\
(
	struct s_init *s_init
)
{
	if (*(s_init->line) != '1' || *(s_init->line + \
	(s_init->old_x_len - 2)) != '1')
		return (1);
	if (s_init->old_x_len != xstrlen(s_init->line))
	{
		if (!xstrchr(s_init->line, '\n'))
			s_init->end = 1;
		else
			return (2);
	}
	s_init->count_p += (short)strclen(s_init->line, 'P');
	s_init->count_e += (short)strclen(s_init->line, 'E');

	// p("%p", s_init->s_g->map);
	// p("%s", findex(s_init->s_g->map, (*s_init).i - 1)->content);
	findex(s_init->s_g->map, (*s_init).i - 1)->content = \
	malloc(s_init->old_x_len);
	if (s_init->count_e > 1 || s_init->count_p > 1)
		return (6);
	s_init->p_p = xstrchr(s_init->line, 'P'); // maybe not need player coords
	s_init->x_p = xstrchr(s_init->line, 'E');
	s_init->s_g->colls += (short)strclen(s_init->line, 'C');
	striter(s_init->line, &check3, s_init);
	if (s_init->x_p)
	{
		s_init->s_g->x_p[0] = s_init->x_p - s_init->line;
		s_init->s_g->x_p[1] = s_init->i - 1;
	}
	if (s_init->p_p)
	{
		*s_init->p_p = '0';
		s_init->s_g->p = malloc(2);
		s_init->s_g->p[0] = (s_init->p_p - s_init->line);
		s_init->s_g->p[1] = s_init->i - 1;
	}
	llend(&s_init->s_g->map)->content = s_init->line;
	// xstrlcpy(findex(s_init->s_g->map, (*s_init).i - 1)->content, \
	s_init->line, s_init->old_x_len + s_init->end);
	return (0);
}

int	check_y_border(char *line)
{
	// p("<%s>", line);
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i])
	{
		if (line[i++] != '1')
			return (1);
	}
	return (0);
}

int	load_map(struct s_init *s_init, char **c)
{
	int		fd_map;

	fd_map = open(*(c + 1), O_RDONLY);
	(*s_init).line = multiRowRead(fd_map);
	// p("\n<%s>", (*s_init).line);
	(*s_init).old_x_len = xstrlen((*s_init).line); //first check_lines(s_init)
	if (check_y_border((*s_init).line))
		return (5);
	(*s_init).i = 1;
	(*s_init).s_g->map = llnew(0);
	while (1)
	{
		s_init->exit_code = check_lines(s_init);
		// p("\nexit[%d %d]\n", s_init->s_g->x_p[0], s_init->s_g->x_p[1]);
		if (s_init->exit_code)
			return (s_init->exit_code);
		(*s_init).old_x_len = xstrlen((*s_init).line);
		// free((*s_init).line);
		(*s_init).line = multiRowRead(fd_map);
		// p("<%s>", (*s_init).line);
		if (s_init->line)
		{
			(*s_init).i++; //optimize
			lladd(&s_init->s_g->map, llnew(0));
		}
		else
			break ;
	}
	s_init->s_g->y_len = s_init->i;
	s_init->s_g->x_len = s_init->old_x_len;
	// p("|%s|", findex(s_init->s_g->map, s_init->i - 1)->content);
	if (check_y_border(llend(&s_init->s_g->map)->content))
		return (7);
	free((*s_init).line);
	close(fd_map);
	return (0);
}

void iter(void *ss)
{
	// p("%s\n", ss);
}
// struct arithmetic
void	wasd(struct s_g *s_g, int *xy, int aa)
{
	if (aa)
	{
		draw_block(xy[0], xy[1], s_g, NULL);
		if (s_g->select != -1)
		{
			draw_block(xy[0] + s_g->set_wasd[s_g->select][0], xy[1] + s_g->set_wasd[s_g->select][1], s_g, s_g->key_map['P']);
			xy[1] += s_g->set_wasd[s_g->select][1];
			xy[0] += s_g->set_wasd[s_g->select][0];
		}
		return ;
	}
	while (s_g->ct < 4)
	{
		s_g->get_wasd[s_g->key_arr[s_g->ct]] = draw_all(s_g, xy[1] + (int)(s_g->set_wasd[s_g->key_arr[s_g->ct]][1])) + xy[0] + (s_g->set_wasd[s_g->key_arr[s_g->ct]][0]);
		s_g->ct++;
	}
	s_g->ct = 0;
	s_g->get_wasd[3] = (draw_all(s_g, xy[1]) + xy[0]);
}

int		update(t_game *s_g)
{
	// usleep(1000000 / 30);
	if (s_g->select == -1)
		return (0);
	wasd(s_g, s_g->p, 0);
	if (s_g->get_wasd[s_g->select][0] == 'E' && s_g->my_colls == s_g->colls)
			xit(0, s_g);
	if (s_g->get_wasd[s_g->select][0] == 'C')
	{
		*s_g->get_wasd[s_g->select] = '0';
		wasd(s_g, s_g->p, 1);
		// lliter(s_g->map, &iter);
		s_g->my_colls++;
	}
	else if(s_g->get_wasd[s_g->select][0] != '1')
		wasd(s_g, s_g->p, 1);
	p("x:%d, y:%d ", s_g->p[0], s_g->p[1]);
	return (1);
}

void dell(void *p)
{
	free(p);
}

void print_alter(t_list *tt)
{
	if (!tt)
		return ;
	while (tt)
	{
		p("<%d, %d> ", ((int *)(tt->content))[0], ((int *)(tt->content))[1]);
		tt = tt->next;
	}
	
}

void check3(unsigned int i, char *ss, void *ptr)
{
	if (ss[0] == 'C')
	{
		llprepend(&((struct s_init *)ptr)->s_g->colls_xy, llnew(0));
		((struct s_init *)ptr)->s_g->colls_xy->content = malloc(sizeof(int) * 2);
		((int *)(((struct s_init *)ptr)->s_g->colls_xy->content))[1] = ((struct s_init *)ptr)->i - 1;
		((int *)(((struct s_init *)ptr)->s_g->colls_xy->content))[0] = i;
	}
}

void replace35(unsigned int i, char *ss, void *ptr)
{
	(void)ptr;
	if (ss[0] == '#')
	{
		ss[0] = '0';
	}
}

void put_coll(void *ptr, void *ptr2)
{
	((char *)(findex(((t_game *)ptr2)->map, ((int *)(((t_list *)ptr)->content))[1])->content))[((int *)(((t_list *)ptr)->content))[0]] = 'C';
}

void restore(void *ptr, void *ptr2)
{
	(void)ptr2;
	striter((char *)(((t_list *)ptr)->content), replace35, NULL);
}

void render(t_game *s_g, t_pf *pf)
{
	((char *)(findex(s_g->map, s_g->x_p[1])->content))[s_g->x_p[0]] = 'E';
	lliter(s_g->colls_xy, put_coll, s_g);
	lliter(s_g->map, restore, NULL);
	s_g->my_colls = 0;
	llclr(&pf->stack, &dell);
	free(pf->p);
}

int	validate_map(struct s_g *s_g, t_pf *pf)
{
	// p("3333333333");
	char	*pointer1;
	// return (0);
	// draw_all(s_g, -1);
	// p("%d\n", s_g->x_len);
	// p("%d\n", s_g->x_len);

	char xy[2];
	t_list	*tmp;
	pf->i = 0;
	pf->p[0] = s_g->p[0];
	pf->p[1] = s_g->p[1];
	pf->stack = NULL;
	// pf->first = 0;
	s_g->select = -1;

	while (1)
	{
		// usleep(10000);
		wasd(s_g, pf->p, 0);
		if (s_g->get_wasd[3][0] == 'E')
		{
			pf->e_flag = 1;
			if (s_g->my_colls == s_g->colls)
				return(0);
		}
		else if (s_g->get_wasd[3][0] == 'C')
		{
			s_g->my_colls++;
			if (pf->e_flag && (s_g->my_colls == s_g->colls))
				return(0);
		}
		// update directions in link
		while (pf->i != 4)
		{
			if (s_g->get_wasd[s_g->key_arr[pf->i]][0] != '1' &&
				s_g->get_wasd[s_g->key_arr[pf->i]][0] != '#')
			{
				if (s_g->select != -1)
				{
					pf->p[2] = 0;
					if (s_g->get_wasd[3][0] != '#')
					{
						tmp = llnew(0);
						tmp->content = malloc(sizeof(int) * 2);
						((int *)(tmp->content))[0] = pf->p[0];
						((int *)(tmp->content))[1] = pf->p[1];
						llprepend(&pf->stack, tmp);
					}
					break ;
				}
				else
					s_g->select = s_g->key_arr[pf->i];
			}
			pf->i++;
		}
		// if (lllen(pf->que) > 1)
		// 	pf->stack->que = pf->que;
		// pf->first;
		// s_g->select = pf->first;
		if (pf->p[2])
		{
			llpop(&pf->stack, dell);
			pf->p[2] = 0;
		}
		if (s_g->select != -1)
		{
			pointer1 = draw_all(s_g, pf->p[1]);
			pointer1[(pf->p)[0]]='#';
			wasd(s_g, pf->p, 1);
			// pf->p[2] = 0;
		}
		else
		{
			if (!lllen(pf->stack))
				break ;
			pointer1 = draw_all(s_g, pf->p[1]);
			pointer1[(pf->p)[0]]='#';
			wasd(s_g, pf->p, 1);
			// p("<%d, %d> ", ((int *)(pf->stack->content))[0], ((int *)(pf->stack->content))[1]);
			pf->p[0] = ((int *)(pf->stack->content))[0];
			pf->p[1] = ((int *)(pf->stack->content))[1];
			pf->p[2] = 1;
			// pop pf->stack
			// draw_block(xy[0] + s_g->set_wasd[s_g->select][0], xy[1] + s_g->set_wasd[s_g->select][1], s_g, s_g->key_map['P']);
			// tp to last alternate path
		}
		pf->i = 0;
		s_g->select = -1;
		// p("%s", s_g->map->content);
		// draw_all(s_g, -1);
		// print_map(s_g);
		// print_alter(pf->stack);
		//
	}
	return (1);
}
