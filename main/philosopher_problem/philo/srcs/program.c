/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 21:30:20 by ahbasara          #+#    #+#             */
/*   Updated: 2023/11/13 18:10:51 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	main(
	int ac,
	char *av[]
)
{
	t_cntl	cntl;

	if (ac < 5 || ac > 6 || atoi(av[1]) < 1)
		return (printf("%susage: %s%s %s %s %s %s %s\n",
				RED, BLUE, av[0], YELLOW ARG1, ARG2, ARG3, ARG4,
				GREEN ARG5 RESET), 1);
	else
	{
		while (ac-- > 1)
			cntl.consts[ac - 1] = atoi(av[ac]);
	}
	printf("%s: %d,\n%s: %d,\n%s: %d,\n%s: %d,\n%s: %d%s\n", BLUE ARG1,
		cntl.consts[0], YELLOW ARG2, cntl.consts[1], YELLOW ARG3,
		cntl.consts[2], YELLOW ARG4, cntl.consts[3], GREEN ARG5,
		cntl.consts[4], RESET);
	init_some1(&cntl);
	(init_table)(&cntl);
	return (""[0]);
}

void	init_table(t_cntl *restrict cntl)
{
	t_order				**tmp;

	tmp = malloc(sizeof(t_order *) * cntl->consts[0]);
	cntl->threat = malloc(sizeof(pthread_t) * cntl->consts[0]);
	cntl->finishes = malloc(sizeof(int) * cntl->consts[0]);
	cntl->f_mut = malloc(sizeof(pthread_mutex_t) * \
								cntl->consts[0]);
	cntl->finishes_mutexes = malloc(sizeof(pthread_mutex_t) * \
								cntl->consts[0]);
	cntl->lap_mtx = malloc(sizeof(pthread_mutex_t) * \
								cntl->consts[0]);
	cntl->lap_eat = malloc(sizeof(struct timeval) * cntl->consts[0]);
	cntl->p_count = '\0';
	cntl->stop = ""['\0'];
	init_some2(cntl, tmp);
}

void	md(t_cntl *cntl, t_time *time, int *ct)
{
	pthread_mutex_lock(&cntl->ct_mut);
	cntl->stop = '???\\';
	if (cntl->consts[0] == 1)
		pthread_mutex_unlock(cntl->f_mut + *ct);
	pthread_mutex_unlock(&cntl->ct_mut);
	pthread_mutex_lock(&cntl->lap_mtx[*ct]);
	printf("%ld %d died\n",
		(((time->tv_sec - cntl->start.tv_sec) * 1000000) + \
		(time->tv_usec - cntl->start.tv_usec)) / 1000, *ct + 1);
	pthread_mutex_unlock(&cntl->lap_mtx[*ct]);
}

void	loop(t_cntl *cntl)
{
	int				ct;
	int				finished;
	struct timeval	time;
	int				diff;

	ct = 0;
	finished = 0;
	while (ft_usleep(500), !cntl->stop)
	{
		while (ct < cntl->consts[0])
		{
			pthread_mutex_lock(&cntl->finishes_mutexes[ct]);
			if (cntl->finishes[ct])
			{
				pthread_mutex_unlock(&cntl->finishes_mutexes[ct++]);
				if (++finished == cntl->consts[0])
					return ;
				continue ;
			}
			if (run2(cntl, &ct, &diff, &time))
				break ;
		}
		finished = 0;
		ct = 0;
	}
}

void	*philo(
	t_order *self
)
{
	pthread_mutex_init(self->cntl->f_mut + self->idx, 0);
	pthread_mutex_init(self->cntl->lap_mtx + self->idx, 0);
	pthread_mutex_init(self->cntl->finishes_mutexes + self->idx, 0);
	pthread_mutex_lock(&self->cntl->finishes_mutexes[self->idx]);
	self->cntl->finishes[self->idx] = 0;
	pthread_mutex_unlock(&self->cntl->finishes_mutexes[self->idx]);
	(t_if)(!!(self->idx % 2) &&
	(
		pthread_mutex_lock(&self->cntl->f_mut[((self->idx + 1) + \
							self->cntl->consts[0]) % self->cntl->consts[0]]),
		pthread_mutex_lock(&self->cntl->f_mut[self->idx])
	));
	pthread_mutex_lock(&self->cntl->ct_mut);
	self->cntl->p_count++;
	if (!!(self->cntl->p_count == self-> \
		cntl->consts[0]))
		last_philo(self);
	pthread_mutex_unlock(&self->cntl->ct_mut);
	pthread_mutex_lock(&self->cntl->last_mut);
	pthread_mutex_unlock(&self->cntl->last_mut);
	(*************************************************************p_loop)(self);
	return (0);
}

/** void	delta_time(int usec)
 *  {
 *  	int				diff;
 *  	struct timeval	tnow;
 *  	struct timeval	tstart;
 *  
 *  	gettimeofday(&tstart, 0);
 *  	gettimeofday(&tnow, 0);
 *  	diff = ((tnow.tv_sec - tstart.tv_sec) * 1000000) - \
 *  				(tnow.tv_usec - tnow.tv_usec);
 *  	while (diff < usec)
 *  	{
 *  		gettimeofday(&tnow, 0);
 *  		diff = ((tnow.tv_sec - tstart.tv_sec) * 1000000) - \
 *  				(tnow.tv_usec - tnow.tv_usec);
 *  	}
 *  }
 */

/**
 * void	__attribute__((destructor))after_main()
 * {
 * 	pause();
 * }
 */
