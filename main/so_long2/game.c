/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 22:56:36 by ahbasara          #+#    #+#             */
/*   Updated: 2023/08/25 22:56:36 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

/* void	print_map(t_game *s_g)
{
	int	i;

	i = 0;
	p("\n[\n");
	while (i < s_g->y_len)
	{
		p("%s", putall(s_g, i));
		i++;
	}
	p("\n]\n");
} */

/* void print_alter(t_list *tt)
{
	if (!tt)
		return ;
	while (tt)
	{
		p("<%d, %d> ", ((int *)(tt->content))[0], ((int *)(tt->content))[1]);
		tt = tt->next;
	}
} */

#include "game.h"

int	draw_block(int x, int y, t_game *s_g)
{
	char	q;
	t_list	*p;

	p = findex(s_g->map, y);
	q = ((char *)(p->content))[x];
	mlx_put_image_to_window(s_g->m_p, s_g->w_p, s_g->km[(int)q], x * \
							16, y * 16);
	return (1);
}

int	draw_b(int x, int y, t_game *s_g, void *img)
{
	return (mlx_put_image_to_window(s_g->m_p, s_g->w_p, img, x * \
			16, y * 16));
}

char	*putall(t_game *s_g, int y)
{
	int		i;
	int		j;
	t_list	*s;

	if (y != -1)
	{
		s = findex(s_g->map, y);
		return ((char *)(s->content));
	}
	i = 0;
	j = 0;
	while (i < s_g->y_len)
	{
		while (j < s_g->x_len)
		{
			draw_block(j, i, s_g);
			j++;
		}
		j = 0;
		i++;
	}
	draw_b(s_g->p[0], s_g->p[1], s_g, s_g->km['P']);
	return (0);
}

void	init1(t_game *s_g, char **c)
{
	struct s_i	*s_i;
	t_pf		*pf;

	s_i = callocate(1, sizeof(struct s_i));
	pf = &(t_pf){};
	s_i->s_g = s_g;
	init3(s_g);
	pf->p = callocate(3, sizeof(int));
	init2(s_g, c, pf, s_i);
}


