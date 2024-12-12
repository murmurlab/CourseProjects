#include "game.h"
#include <fcntl.h>
#include <errno.h>

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
	if (!strnstr(*(c + 1), ".ber", xstrlen(*(c + 1))))
		abandonner(s_g, s_i, "ext not end with .ber", 0);
	*fd_map = open(*(c + 1), O_RDONLY);
	if (*fd_map < 3)
		abandonner(s_g, s_i, 0, errno);
	(*s_i).line = multi_get_line(*fd_map);
	s_i->line[xstrlen(s_i->line) - 1] = 0;
	(*s_i).oldlen = xstrlen((*s_i).line);
	if (check_y_border((*s_i).line))
		abandonner(s_g, s_i, "0y border err", 0);
	(*s_i).i = 1;
	(*s_i).s_g->map = llnew(0);
}

void	check_lines2(struct s_i *s_i)
{
	s_i->p_p = xstrchr(s_i->line, 'P');
	s_i->x_p = xstrchr(s_i->line, 'E');
	s_i->s_g->colls += (short)strclen(s_i->line, 'C');
	striter(s_i->line, &check3, s_i);
	if (s_i->x_p)
	{
		s_i->s_g->x_p[0] = s_i->x_p - s_i->line;
		s_i->s_g->x_p[1] = s_i->i - 1;
	}
	if (s_i->p_p)
	{
		*s_i->p_p = '0';
		s_i->s_g->p = (int *)callocate(2, sizeof(int));
		s_i->s_g->p[0] = (int)(s_i->p_p - s_i->line);
		s_i->s_g->p[1] = s_i->i - 1;
	}
}

void	step(t_game *s_g)
{
	int	x;
	int	y;

	x = 0;
	y = 10;
	p("<step: %d> ", s_g->step++);
	draw_block(x / 16, y / 16, s_g);
	draw_block((x / 16) + 1, y / 16, s_g);
	mlx_string_put(s_g->m_p, s_g->w_p, x, y, 0xffffffff, x_itoa(s_g->step));
}
