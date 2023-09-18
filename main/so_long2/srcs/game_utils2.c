/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 03:11:46 by ahbasara          #+#    #+#             */
/*   Updated: 2023/08/31 14:04:48 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	resolve_key(t_game *sgame)
{
	if (sgame->direction[0] == 1)
		sgame->select = D;
	if (sgame->direction[0] == -1)
		sgame->select = A;
	if (sgame->direction[1] == 1)
		sgame->select = S;
	if (sgame->direction[1] == -1)
		sgame->select = W;
	if (sgame->direction[0] == 0 && sgame->direction[1] == 0)
		sgame->select = -1;
}

int	events_d(int k, void *rr)
{
	p("\nkey<%d> ", k);
	if (k == 53 || k == 65307)
		abandonner(*(void **)rr, 0, "esc", 0);
	if (k != W && k != A && k != S && k != D)
		return (0);
	(*(t_game **)rr)->select = k;
	(*(t_game **)rr)->direction[0] += (*(t_game **)rr)->set[k][0];
	(*(t_game **)rr)->direction[1] += (*(t_game **)rr)->set[k][1];
	return (0);
}

int	loop(void *rr)
{
	if (((*(t_game **)rr)->loop)++ == 500)
	{
		update(*(void **)rr);
		(*(t_game **)rr)->loop = 0;
	}
	return (0);
}

int	main(int c, char *v[])
{
	(void)c;
	t_game	*s_g;
	int		*asd;

	s_g = callocate(sizeof(t_game), 1);
	s_g->direction[0] = 0;
	s_g->direction[1] = 0;
	s_g->select = -1;
	s_g->ct = 0;
	s_g->map = 0;
	s_g->colls = 0;
	s_g->my_colls = 0;
	s_g->end = 0;
	s_g->m_p = mlx_init();
	s_g->km[48] = mlx_xpm_file_to_image(s_g->m_p, "a/0.xpm", &s_g->g, &s_g->y);
	s_g->km[80] = mlx_xpm_file_to_image(s_g->m_p, "a/P.xpm", &s_g->g, &s_g->y);
	s_g->km[49] = mlx_xpm_file_to_image(s_g->m_p, "a/1.xpm", &s_g->g, &s_g->y);
	s_g->km[69] = mlx_xpm_file_to_image(s_g->m_p, "a/E.xpm", &s_g->g, &s_g->y);
	s_g->km[67] = mlx_xpm_file_to_image(s_g->m_p, "a/C.xpm", &s_g->g, &s_g->y);
	s_g->km[35] = mlx_xpm_file_to_image(s_g->m_p, "a/1.xpm", &s_g->g, &s_g->y);
	s_g->set[W][0] = 0;
	s_g->set[W][1] = -1;
	asd = (int [2]){2};
	p("BUFFER_SIZE: %d\n", BUFFER_SIZE);
	init1(s_g, v);
}

void	wasd(struct s_g *s_g, int *xy, int aa, char ch)
{
	if (aa)
	{
		draw_block(xy[0], xy[1], s_g);
		if (s_g->select != -1)
		{
			draw_b(xy[0] + s_g->set[s_g->select][0], xy[1] + s_g->\
			set[s_g->select][1], s_g, s_g->km[(int)ch]);
			xy[1] += s_g->set[s_g->select][1];
			xy[0] += s_g->set[s_g->select][0];
		}
		return ;
	}
	while (s_g->ct < 4)
	{
		s_g->get[s_g->karr[s_g->ct]] = putall(s_g, xy[1] + (int)(s_g-> set[\
		s_g->karr[s_g->ct]][1])) + xy[0] + (s_g->set[s_g->karr[s_g->ct]][0]);
		s_g->ct++;
	}
	s_g->ct = 0;
	s_g->get[3] = (putall(s_g, xy[1]) + xy[0]);
}
