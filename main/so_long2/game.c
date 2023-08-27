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
#include <signal.h>

int	xit(int x, t_game *s_g)
{
	free(s_g->key_map[48]);
	free(s_g->key_map[80]);
	free(s_g->key_map[49]);
	free(s_g->key_map[69]);
	free(s_g->key_map[67]);
	free(s_g->key_map[35]);
	free(s_g->p);
	llclr(&s_g->colls_xy, &dell);
	llclr(&s_g->map, &dell);
	exit(x);
}

void	print_map(t_game *s_g)
{
	int	i;

	i = 0;
	p("\n[\n");
	while (i < s_g->y_len)
	{
		p("%s", draw_all(s_g, i));
		i++;
	}
	p("\n]\n");
}

int	draw_block(int x, int y, t_game *s_g, void *img)
{
	char	q;

	if (img)
		return (mlx_put_image_to_window(s_g->mlx_p, s_g->w_p, img, x * \
				16, y * 16));
	q = ((char *)(findex(s_g->map, y)->content))[x];
	// p("zz: %c, %d", q, s_g->key_map[q]);
	mlx_put_image_to_window(s_g->mlx_p, s_g->w_p, s_g->key_map[q], x *\
							16, y * 16);
	// p("draw_block: w<%d>, h<%d>\n", s_g->w, s_g->h);
	return (1);
}

char	*draw_all(t_game *s_g, int y)
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
			draw_block(j, i, s_g, NULL);
			j++;
		}
		j = 0;
		i++;
	}
	draw_block(s_g->p[0], s_g->p[1], s_g, s_g->key_map['P']);
	return (0);
}

int	events_u(int k, struct s_g *s_g)
{
	// validate_map(s_g, pf);
	p("\nkey<%d> ", k);
	// s_g->select = -1;

	s_g->direction[0] -= s_g->set_wasd[k][0];
	s_g->direction[1] -= s_g->set_wasd[k][1];
	resolve_key(s_g);
	return (0);
}

int	init1(t_game *s_g, char **c)
{
	struct s_init	s_init;
	t_pf				*pf;
	void				*rr;

	rr = malloc(sizeof(void *) * 2);
	pf = &(t_pf){};
	*(((void **)rr) + 1)= pf;
	pf->p = malloc(3 * sizeof(int));
	s_init.end = 0;
	s_init.p_p = 0;
	s_init.x_p = 0;
	s_init.exit_code = 0;
	s_init.count_e = 0;
	s_init.count_p = 0;
	s_g = &(t_game){0, {0, 0}, (char [W + 1][2]){}, -1, 0, (char *[W + 1]\
			){}, NULL, NULL, 0, 0, {}, (void *[81]){}\
			, NULL, NULL, 0, 0, 0, 0, NULL, (int [2]){}, 0};
	*(((void **)rr) + 0) = s_g;
	s_init.s_g = s_g;
	// p("\n||%d||", s_init.s_g->select);
	// p("\n||%p, %p||", s_init.s_g, s_g);
	// s_g->loop = 0;
	// s_g->colls = 0;
	// s_g->my_colls = 0;
	// s_g->end = 0;
	// s_g->ct = 0;
	// s_g->colls_xy = NULL;
	s_g->mlx_p = mlx_init();
	s_g->key_map[48] = mlx_xpm_file_to_image(s_g->mlx_p, "assets/bg.xpm", &s_g->wt, &s_g->hh);
	s_g->key_map[80] = mlx_xpm_file_to_image(s_g->mlx_p, "assets/ghasta.xpm", &s_g->wt, &s_g->hh);
	s_g->key_map[49] = mlx_xpm_file_to_image(s_g->mlx_p, "assets/wall.xpm", &s_g->wt, &s_g->hh);
	s_g->key_map[69] = mlx_xpm_file_to_image(s_g->mlx_p, "assets/exit_1.xpm", &s_g->wt, &s_g->hh);
	s_g->key_map[67] = mlx_xpm_file_to_image(s_g->mlx_p, "assets/main_c.xpm", &s_g->wt, &s_g->hh);
	s_g->key_map[35] = mlx_xpm_file_to_image(s_g->mlx_p, "assets/wall.xpm", &s_g->wt, &s_g->hh);
	s_g->set_wasd[W][0] = 0;
	s_g->set_wasd[W][1] = -1;
	s_g->set_wasd[A][0] = -1;
	s_g->set_wasd[A][1] = 0;
	s_g->set_wasd[S][0] = 0;
	s_g->set_wasd[S][1] = 1;
	s_g->set_wasd[D][0] = 1;
	s_g->set_wasd[D][1] = 0;
	s_g->map = malloc(sizeof(t_list));
	s_g->select = -1;
	s_g->key_arr[0] = W;
	s_g->key_arr[1] = A;
	s_g->key_arr[2] = S;
	s_g->key_arr[3] = D;
	pf->e_flag = 0;
	s_init.exit_code = load_map(&s_init, c);
	// print_alter(s_g->colls_xy);
	// p("\n||%p, %p||", s_init.s_g, s_g);
	// p("\nexit[%d %d]\n", s_g->x_p[0], s_g->x_p[1]);
	// p("\nexit[%d %d]\n", s_init.s_g->x_p[0], s_init.s_g->x_p[1]);
	if (s_init.exit_code)
	{
		p("error load map1: %d\n", s_init.exit_code);
		return (1);
	}
	// p("asd5");
	s_g->w_p = mlx_new_window(s_g->mlx_p, s_g->hh * s_g->x_len, s_g->wt * s_g->y_len, "game");
	// p("asd444444444444444444");
	draw_all(s_g, -1);
	// p("asd3");
	mlx_hook(s_g->w_p, 2, 1L<<0, &events_d, rr);
	mlx_hook(s_g->w_p, 3, 1L<<0, &events_u, s_g);
	mlx_loop_hook(s_g->mlx_p, loop, rr);
	mlx_do_key_autorepeatoff(s_g->mlx_p);
	s_init.exit_code = validate_map(s_g, pf);
	render(s_g, pf);
	draw_all(s_g, -1);
	if (s_init.exit_code)
	{
		p("invalid map: %d\n", s_init.exit_code);
		xit(0, s_g);
	}
	mlx_loop(s_g->mlx_p);
	// p("asd");
	render(s_g, pf);
	draw_all(s_g, -1);
	return (0);
}
