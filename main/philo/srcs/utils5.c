/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 21:30:20 by ahbasara          #+#    #+#             */
/*   Updated: 2023/11/11 23:54:57 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	run(t_cntl *cntl, int *ct, int *diff, t_time *time)
{
	pthread_mutex_unlock(&cntl->finishes_mutexes[*ct]);
	gettimeofday(time, 0);
	pthread_mutex_lock(&cntl->lap_mtx[*ct]);
	*diff = ((time->tv_sec - cntl->lap_eat[*ct].tv_sec) * 1000000) + \
			((time->tv_usec - cntl->lap_eat[*ct].tv_usec));
	pthread_mutex_unlock(&cntl->lap_mtx[*ct]);
}

int	run2(t_cntl *cntl, int *ct, int *diff, t_time *time)
{
	run(cntl, ct, diff, time);
	if ((*diff > (cntl->consts[1] * 1000)) && (md(cntl, time, ct), 1))
		return (1);
	else
		(*ct)++;
	return (0);
}

void	unlock(t_order *self)
{
	pthread_mutex_unlock(&self->cntl->f_mut[idx(self->idx + 1, \
						self->cntl->consts[0])]);
	pthread_mutex_unlock(&self->cntl->f_mut[self->idx]);
}
