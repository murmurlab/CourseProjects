/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 09:39:08 by ahbasara          #+#    #+#             */
/*   Updated: 2023/08/27 10:25:19 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	validate4(t_pf *pf, t_game *s_g)
{
	pf->i = 0;
	pf->p[0] = s_g->p[0];
	pf->p[1] = s_g->p[1];
	pf->stack = NULL;
	s_g->select = -1;
}

void	load_map2(struct s_i *s_i, int *fd_map, char **c, t_game *s_g)
{
	*fd_map = open(*(c + 1), O_RDONLY);
	(*s_i).line = multiRowRead(*fd_map);
	(*s_i).oldlen = xstrlen((*s_i).line);
	if (check_y_border((*s_i).line))
	{
		free(s_g->map);
		p("snt");
		exit(0);
	}
	(*s_i).i = 1;
	(*s_i).s_g->map = llnew(0);
}
