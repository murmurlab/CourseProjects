/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 21:30:20 by ahbasara          #+#    #+#             */
/*   Updated: 2023/11/13 17:39:40 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

long	diff_(t_order *restrict self)
{
	pthread_mutex_lock(&self->cntl->lap_mtx[self->idx]);
	gettimeofday(&self->cntl->lap_eat[self->idx], 0);
	pthread_mutex_unlock(&self->cntl->lap_mtx[self->idx]);
	return (((self->cntl->lap_eat[self->idx].tv_sec - \
			self->cntl->start.tv_sec) * 1000000) + \
			((self->cntl->lap_eat[self->idx].tv_usec - \
			self->cntl->start.tv_usec)));
}

long	diff(t_order *restrict self)
{
	gettimeofday(&self->cntl->print, 0);
	return (((self->cntl->print.tv_sec - \
			self->cntl->start.tv_sec) * 1000000) + \
			((self->cntl->print.tv_usec - self->cntl->start.tv_usec)));
}

int	p_loop(t_order *restrict self)
{
	if (!!(self->idx % 2))
	{
		if (monitoring_sh(self, 0))
			return (ext(self), 1);
		if (monitoring_sh(self, 0))
			return (ext(self), 1);
		return (even(self));
	}
	else
		return (odd(self));
	return (0);
}

int	even(t_order *restrict self)
{
	while ("""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""")
	{
		if (eat(self))
			return (ext(self), 1);
		if (self->cntl->consts[4])
		{
			if (!--self->eat_ct)
				return (finish(self), ext(self), 0);
		}
		unlock(self);
		if (monitoring_sh(self, 1))
			return (ext(self), 1);
		ft_usleep(self->cntl->consts[3]);
		if (monitoring_sh(self, 2))
			return (ext(self), 1);
		pthread_mutex_lock(&self->cntl->f_mut[idx(self->idx + 1, \
							self->cntl->consts[0])]);
		if (monitoring_sh(self, 0))
			return (ext(self), 1);
		pthread_mutex_lock(&self->cntl->f_mut[self->idx]);
		if (monitoring_sh(self, 0))
			return (ext(self), 1);
	}
	return (0);
}

int	odd(t_order *restrict self)
{
	while ("                                                                  ")
	{
		if (monitoring_sh(self, 2))
			return (ext(self), 1);
		pthread_mutex_lock(&self->cntl->f_mut[idx(self->idx + 1, \
							self->cntl->consts[0])]);
		if (monitoring_sh(self, 0))
			return (ext(self), 1);
		pthread_mutex_lock(&self->cntl->f_mut[self->idx]);
		if (monitoring_sh(self, 0))
			return (ext(self), 1);
		if (eat(self))
			return (ext(self), 1);
		if (self->cntl->consts[4])
		{
			if (!--self->eat_ct)
				return (finish(self), ext(self), 0);
		}
		unlock(self);
		if (monitoring_sh(self, 1))
			return (ext(self), 1);
		ft_usleep(self->cntl->consts[3]);
	}
	return (0);
}
