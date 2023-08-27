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

void	dell(void *p)
{
	free(p);
}

int	draw_block(int x, int y, t_game *s_g)
{
	char	q;

	q = ((char *)(findex(s_g->map, y)->content))[x];
	mlx_put_image_to_window(s_g->m_p, s_g->w_p, s_g->km[q], x * \
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

	if (y != -1)
		return ((char *)(findex(s_g->map, y)->content));
	i = 0;
	j = 0;
	while (i < s_g->y_len)
	{
		while (j < s_g->x_len - 1)
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

int	init1(t_game *s_g, char **c)
{
	struct s_i	s_i;
	t_pf		*pf;

	pf = &(t_pf){};
	pf->e_flag = 0;
	s_i.s_g = s_g;
	s_i.end = 0;
	s_i.p_p = 0;
	s_i.x_p = 0;
	s_i.exit_code = 0;
	s_i.count_e = 0;
	s_i.count_p = 0;
	init3(s_g);
	pf->p = malloc(3 * sizeof(int));
	return (init2(s_g, c, pf, &s_i));
}
