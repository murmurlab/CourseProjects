/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 08:31:04 by ahbasara          #+#    #+#             */
/*   Updated: 2023/08/31 15:17:33 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	events_u(int k, struct s_g *s_g)
{
	p("\nkey<%d> ", k);
	s_g->direction[0] -= s_g->set[k][0];
	s_g->direction[1] -= s_g->set[k][1];
	resolve_key(s_g);
	return (0);
}

void	replace35(unsigned int i, char *ss, void *ptr)
{
	(void)i;
	(void)ptr;
	if (ss[0] == '#')
	{
		ss[0] = '0';
	}
}

void	put_coll(void *ptr, void *ptr2)
{
	p("<%d>", ((int *)ptr)[0]);
	p("<%d> ", ((int *)ptr)[1]);
	((char *)(findex(((t_game *)ptr2)->map, ((int *)ptr)[1])->content))[((int \
		*)ptr)[0]] = 'C';
}

void	restore(void *ptr, void *ptr2)
{
	(void)ptr2;
	striter((char *)ptr, replace35, NULL);
}

void	render(t_game *s_g, t_pf *pf)
{
	((char *)(findex(s_g->map, s_g->x_p[1])->content))[s_g->x_p[0]] = 'E';
	lliter(s_g->colls_xy, put_coll, s_g);
	lliter(s_g->map, restore, NULL);
	s_g->my_colls = 0;
	llclr(&pf->stack, &freedom);
	freedom((void **)&pf->p);
}
