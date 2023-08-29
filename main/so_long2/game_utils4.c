/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 09:39:08 by ahbasara          #+#    #+#             */
/*   Updated: 2023/08/29 08:39:21 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	init2(t_game *s_g, char **c, t_pf *pf, struct s_i *s_i)
{
	void	*rr;

	s_i->exit_code = load_map(s_i, c, s_g);
	rr = malloc(sizeof(void *) * 2);
	*(((void **)rr) + 0) = s_g;
	*(((void **)rr) + 1) = pf;
	if (s_i->exit_code)
		return (p("error load map1: %d\n", s_i->exit_code), 1);
	s_g->w_p = mlx_new_window(s_g->m_p, s_g->y * (s_g->x_len - 1), s_g->g * \
	s_g->y_len, "game");
	putall(s_g, -1);
	mlx_hook(s_g->w_p, 2, 1L << 0, &events_d, rr);
	mlx_hook(s_g->w_p, 3, 1L << 0, &events_u, s_g);
	mlx_loop_hook(s_g->m_p, loop, rr);
	mlx_do_key_autorepeatoff(s_g->m_p);
	s_i->exit_code = validate_map(s_g, pf);
	render(s_g, pf, 3000);
	putall(s_g, -1);
	if (s_i->exit_code)
	{
		p("invalid map: %d\n", s_i->exit_code);
		render(s_g, 0, 0);
	}
	mlx_loop(s_g->m_p);
	return (0);
}

void	init3(t_game *s_g)
{
	s_g->colls_xy = 0;
	s_g->enemy_xy = 0;
	s_g->set[A][0] = -1;
	s_g->set[A][1] = 0;
	s_g->set[S][0] = 0;
	s_g->set[S][1] = 1;
	s_g->set[D][0] = 1;
	s_g->set[D][1] = 0;
	s_g->p_anim[0] = mlx_xpm_file_to_image(s_g->m_p, "a/P.xpm", &s_g->g, \
	&s_g->y);
	s_g->p_anim[1] = mlx_xpm_file_to_image(s_g->m_p, "a/ghast.xpm", &s_g->g, \
	&s_g->y);
	s_g->step = 0;
	s_g->map = llnew(0);
	s_g->karr[0] = W;
	s_g->karr[1] = A;
	s_g->karr[2] = S;
	s_g->karr[3] = D;
}

int	validate_map(struct s_g *s_g, t_pf *pf)
{
	char	*pointer1;
	char	xy[2];
	t_list	*tmp;

	validate4(pf, s_g);
	while (1)
	{
		wasd(s_g, pf->p, 0, '\0');
		if (s_g->get[3][0] == 'E')
		{
			pf->e_flag = 1;
			if (s_g->my_colls == s_g->colls)
				return (0);
		}
		else if (s_g->get[3][0] == 'C')
		{
			s_g->my_colls++; 
			if (pf->e_flag && (s_g->my_colls == s_g->colls))
				return (0);
		}
		validate2(pf, tmp, s_g);
		if (validate3(pf, s_g, &pointer1))
			break ;
	}
	return (1);
}

void	validate2(t_pf *pf, t_list *tmp, t_game *s_g)
{
	while (pf->i != 4)
	{
		if (s_g->get[s_g->karr[pf->i]][0] != '1' &&
			s_g->get[s_g->karr[pf->i]][0] != '#')
		{
			if (s_g->select != -1)
			{
				pf->p[2] = 0;
				if (s_g->get[3][0] != '#')
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
				s_g->select = s_g->karr[pf->i];
		}
		pf->i++;
	}
	return ;
}

int	validate3(t_pf *pf, t_game *s_g, char **pointer1)
{
	if (pf->p[2])
	{
		llpop(&pf->stack, dell);
		pf->p[2] = 0;
	}
	if (s_g->select != -1)
	{
		*pointer1 = putall(s_g, pf->p[1]);
		(*pointer1)[(pf->p)[0]] = '#';
		wasd(s_g, pf->p, 1, 'P');
	}
	else
	{
		if (!lllen(pf->stack))
			return (1);
		*pointer1 = putall(s_g, pf->p[1]);
		(*pointer1)[(pf->p)[0]] = '#';
		wasd(s_g, pf->p, 1, 'P');
		pf->p[0] = ((int *)(pf->stack->content))[0];
		pf->p[1] = ((int *)(pf->stack->content))[1];
		pf->p[2] = 1;
	}
	pf->i = 0;
	s_g->select = -1;
	return (0);
}
