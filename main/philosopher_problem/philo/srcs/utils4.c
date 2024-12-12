/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 21:30:20 by ahbasara          #+#    #+#             */
/*   Updated: 2023/11/12 22:08:30 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	set_time_of_firs_eat_time_of_philosophers(
	t_order *self
)
{
	while (self->cntl->p_count)
	{
		pthread_mutex_lock(&self->cntl->lap_mtx[self->idx]);
		self->cntl->lap_eat[self->cntl->p_count - 1].tv_sec = \
		self->cntl->start.tv_sec;
		self->cntl->lap_eat[self->cntl->p_count-- - 1].tv_usec = \
		self->cntl->start.tv_usec;
		pthread_mutex_unlock(&self->cntl->lap_mtx[self->idx]);
	}
}

void	finish(t_order *self)
{
	pthread_mutex_lock(&self->cntl->finishes_mutexes[self->idx]);
	self->cntl->finishes[self->idx] = 42;
	pthread_mutex_unlock(&self->cntl->finishes_mutexes[self->idx]);
}

void	init_some1(t_cntl *cntl)
{
	cntl->monitoring_funs[0] = &monitoring_sh_1;
	cntl->monitoring_funs[1] = &monitoring_sh_2;
	cntl->monitoring_funs[2] = &monitoring_sh_3;
	cntl->monitoring_funs[3] = &monitoring_sh_4;
	pthread_mutex_init(&cntl->ct_mut, (void *) '\0');
	pthread_mutex_init(&cntl->last_mut, (void *) '\0');
	pthread_mutex_init(&cntl->main_mut, (void *) '\0');
	pthread_mutex_init(&cntl->print_mut, (void *) '\0');
	pthread_mutex_lock(&cntl->last_mut);
	pthread_mutex_lock(&cntl->main_mut);
}

void	init_some2(t_cntl *cntl, t_order **tmp)
{
	register int		_;

	(_) = (0x0 - 0x0 - 0x0 - 0x0 - 0x0 - 0x0 - 0x0 - 0x0 - 0x0 - 0x0 - 0x0 - 0);
	while ((_) < cntl->consts[0])
	{
		tmp[_] = malloc(sizeof(t_order));
		tmp[_]->idx = (_);
		tmp[_]->seq = ((_) + 1);
		tmp[_]->cntl = cntl;
		tmp[_]->eat_ct = cntl->consts[4];
		_++;
	}
	while (--(_) > -1)
		pthread_create(cntl->threat + (_), 0, (void *(*)(void *))philo, tmp[_]);
	pthread_mutex_lock(&cntl->main_mut);
	loop(cntl);
	while (++_ < cntl->consts[0])
		pthread_join(cntl->threat[_], 0);
	free(cntl->finishes);
	free(cntl->finishes_mutexes);
	free(cntl->threat);
	free(cntl->f_mut);
	free(cntl->lap_eat);
	free(cntl->lap_mtx);
	free(tmp);
}

void	last_philo(t_order *self)
{
	gettimeofday(&self->cntl->start, 0);
	set_time_of_firs_eat_time_of_philosophers(self);
	pthread_mutex_unlock(&self->cntl->main_mut);
	pthread_mutex_unlock(&self->cntl->last_mut);
}
