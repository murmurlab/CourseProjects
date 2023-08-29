/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils6.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:37:10 by ahbasara          #+#    #+#             */
/*   Updated: 2023/08/29 15:36:38 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	animate_player(t_game *s_g)
{
	static int	stat;

	draw_b(s_g->p[0], s_g->p[1], s_g, s_g->p_anim[stat++]);
	if (stat == 2)
		stat = 0;
}

void	menemy(void *content, void *s_g)
{
	if (((char *)(findex(((t_game *)s_g)->map, ((int *)content)[1])))[((int \
	*)content)[0 + ((int *)content)[2]]] != \
	'1')
		((int *)content)[0] += ((int *)content)[2]; 
	else
		((int *)content)[2] = -1;
	draw_b(((int *)content)[0], ((int *)content)[1], ((t_game *)s_g), ((t_game \
	*)s_g)->km[88]);
}

void	move_enemy(t_game *s_g)
{
	lliter(s_g->enemy_xy, &menemy, s_g);

	// draw_b(s_g->p[0], s_g->p[1], s_g, s_g->p_anim[stat++]);
	// if (stat == 2)
	// 	stat = 0;
}