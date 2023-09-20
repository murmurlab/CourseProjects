/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils6.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:37:10 by ahbasara          #+#    #+#             */
/*   Updated: 2023/08/31 15:18:31 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <string.h>
#include <stdio.h>
#include <errno.h>

void	animate_player(t_game *s_g)
{
	static int	stat;

	draw_b(s_g->p[0], s_g->p[1], s_g, s_g->p_anim[stat++]);
	if (stat == 2)
		stat = 0;
}

void	forbidden_ch(unsigned int i, char *str, void *p)
{
	(void)i;
	if (str[0] == 'P' | str[0] == '0' | str[0] == '1' | str[0] == 'C' | str[0] \
		== 'E')
		return ;
	((struct s_i *)p)->f_line = 1;
}

void	abandonner(t_game *s_g, struct s_i *s_i, char *str, int no)
{
	void	*ptr;

	if (s_i)
		ptr = s_i->s_g;
	else
	{
		ptr = s_g;
		abandonner2(s_g);
		mlx_destroy_window(((t_game *)ptr)->m_p, ((t_game *)ptr)->w_p);
	}
	freedom((void **)(&((t_game *)ptr)->pf->p));
	llclr(&((t_game *)ptr)->pf->stack, &freedom);
	freedom((void **)&((t_game *)ptr)->p);
	llclr(&((t_game *)ptr)->map, &freedom);
	llclr(&((t_game *)ptr)->colls_xy, &freedom);
	freedom((void **)&s_i);
	freedom((void **)&ptr);
	errno = no;
	if (errno)
		perror("Error");
	else
		p("%s", str);
	exit(no);
}

void	abandonner2(t_game *s_g)
{
	mlx_destroy_image(s_g->m_p, s_g->km[48]);
	mlx_destroy_image(s_g->m_p, s_g->km[80]);
	mlx_destroy_image(s_g->m_p, s_g->km[49]);
	mlx_destroy_image(s_g->m_p, s_g->km[69]);
	mlx_destroy_image(s_g->m_p, s_g->km[67]);
	mlx_destroy_image(s_g->m_p, s_g->km[35]);
	mlx_destroy_image(s_g->m_p, s_g->p_anim[0]);
	mlx_destroy_image(s_g->m_p, s_g->p_anim[1]);
}

int	check_lines(struct s_i *s_i)
{
	striter(s_i->line, &forbidden_ch, s_i);
	if (s_i->f_line)
		abandonner(0, s_i, "forbidden char", 0);
	if (*(s_i->line) != '1' || *(s_i->line + (s_i->oldlen - 1)) != '1')
		return (1);
	if (s_i->oldlen != (int)xstrlen(s_i->line))
	{
		if (!xstrchr(s_i->line, '\n'))
			s_i->end = 1;
		else
			return (2);
	}
	s_i->count_p += (short)strclen(s_i->line, 'P');
	s_i->count_e += (short)strclen(s_i->line, 'E');
	if (s_i->count_e > 1 || s_i->count_p > 1)
		return (6);
	check_lines2(s_i);
	llend(s_i->s_g->map)->content = s_i->line;
	p("%s\n", ((char *)(findex(s_i->s_g->map, s_i->i - 1)->content)));
	return (0);
}
