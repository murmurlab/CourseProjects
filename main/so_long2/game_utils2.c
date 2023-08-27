/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 03:11:46 by ahbasara          #+#    #+#             */
/*   Updated: 2023/08/27 03:12:45 by ahbasara         ###   ########.fr       */
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
		xit(0, *(void **)rr);
	if (k != W && k != A && k != S && k != D)
		return (0);
	(*(t_game **)rr)->select = k;
	(*(t_game **)rr)->direction[0] += (*(t_game **)rr)->set_wasd[k][0];
	(*(t_game **)rr)->direction[1] += (*(t_game **)rr)->set_wasd[k][1];
	// resolve_key((*(t_game **)rr));
	// update(*(void **)rr);
	return (0);
}

int loop(void *rr)
{
	// usleep(1000000 / 30);
	// draw_all(*(void **)rr, -1);
	// validate_map(*(void **)rr, *(((void **)rr) + 1));
	if (((*(t_game **)rr)->loop)++ == 500)
	{
		update(*(void **)rr);
		(*(t_game **)rr)->loop = 0;
	}
	return (0);
}

int	main(int c, char *v[])
{
	t_game	*s_g;
	int		*asd;

	asd = (int [2]){2};
	// s_g = malloc(sizeof(t_game));
	s_g = NULL;
	p("BUFFER_SIZE: %d\n", BUFFER_SIZE);
	// s_g->mlx_p = mlx_init();
	// p("asd1");
	if (init1(s_g, v))
		return (1);
	// mlx_loop(s_g->mlx_p);
}