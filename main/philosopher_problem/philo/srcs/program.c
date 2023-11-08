/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 21:30:20 by ahbasara          #+#    #+#             */
/*   Updated: 2023/11/08 14:53:26 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"
#include <sys/time.h>

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
	// int f(), (*pf)(); 
	(init_table)(&cntl);
	return (""[0]);
}

void	init_table(t_cntl *restrict cntl)
{
	register int		_;
	t_order				**tmp;

	(_) = (0 - 0 - 0 - 0 - 0 - 0 - 000000000000000 - 0 - 0 - 0 - 0 - 0 - 0 - 0);
	tmp = malloc(sizeof(t_order *) * cntl->consts[0]);
	cntl->threat = malloc(sizeof(pthread_t) * cntl->consts[0]);
	cntl->f_mut = malloc(sizeof(pthread_mutex_t) * \
								cntl->consts[0]);
	cntl->lap_mtx = malloc(sizeof(pthread_mutex_t) * \
								cntl->consts[0]);
	cntl->lap_eat = malloc(sizeof(struct timeval) * cntl->consts[0]);
	cntl->p_count = '\0';
	cntl->stop = ""['\0'];
	pthread_mutex_init(&cntl->ct_mut, (void *) '\0');
	pthread_mutex_init(&cntl->last_mut, (void *) '\0');
	pthread_mutex_init(&cntl->main_mut, (void *) '\0');
	pthread_mutex_lock(&cntl->last_mut);
	pthread_mutex_lock(&cntl->main_mut);
	while ((_) < cntl->consts[0])
	{
		tmp[_] = malloc(sizeof(t_order));
		tmp[_]->idx = (_);
		tmp[_]->seq = ((_) + 1);
		tmp[_]->cntl = cntl;
		_++;
	}
	while (--(_) > -1)
		pthread_create(cntl->threat + (_), 0, (void *(*)(void *))philo, tmp[_]);
	printf("main wait\n");
	pthread_mutex_lock(&cntl->main_mut);
	pthread_mutex_unlock(&cntl->main_mut);
	printf("main cycle\n");
	loop(cntl);
	while (++_ < cntl->consts[0])
	{
		// printf("join %d\n", _);
		pthread_join(cntl->threat[_], 0);
	}
	// pause();
}

void	loop(t_cntl *cntl)
{
	int				ct;
	struct timeval	time;
	int				diff;

	ct = 0;
	printf("death check loop\n");
	while (!cntl->stop)
	{
		// usleep(5000);
		while (ct < cntl->consts[0])
		{
			gettimeofday(&time, 0);
			pthread_mutex_lock(&cntl->lap_mtx[ct]);
			diff = ((time.tv_sec - cntl->lap_eat[ct].tv_sec) * 1000000) + \
					((time.tv_usec - cntl->lap_eat[ct].tv_usec));
			pthread_mutex_unlock(&cntl->lap_mtx[ct]);
			if (diff > \
				(cntl->consts[1] * 1000))
			{
				pthread_mutex_lock(&cntl->ct_mut);
				cntl->stop = '???\\';
				pthread_mutex_unlock(&cntl->ct_mut);
				pthread_mutex_lock(&cntl->lap_mtx[ct]);
				printf("%ld %ld\n%d %d\n%d\n",
					time.tv_sec, cntl->lap_eat[ct].tv_sec,
					time.tv_usec, cntl->lap_eat[ct].tv_usec, diff);
				printf("%ld %d died\n",
					(((time.tv_sec - cntl->start.tv_sec) * 1000000) + \
					(time.tv_usec - cntl->start.tv_usec)) / 1000, ct + 1);
				// sleep(2);
				pthread_mutex_unlock(&cntl->lap_mtx[ct]);
				break ;
			}
			else
				ct++;
		}
		ct = 0;
	}
}

void	*philo(
	t_order *self
)
{
	pthread_mutex_init(self->cntl->f_mut + self->idx, 0);
	pthread_mutex_init(self->cntl->lap_mtx + self->idx, 0);
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
	{
		// printf("unlock last_mut\n");
		gettimeofday(&self->cntl->start, 0);
		printf("start %ld %d\n", self->cntl->start.tv_sec, self->cntl->start.tv_usec);
		while (self->cntl->p_count)
		{
			self->cntl->lap_eat[self->cntl->p_count - 1].tv_sec = \
			self->cntl->start.tv_sec;
			self->cntl->lap_eat[self->cntl->p_count-- - 1].tv_usec = \
			self->cntl->start.tv_usec;
		}
		printf("end settt\n");
		pthread_mutex_unlock(&self->cntl->main_mut);
		pthread_mutex_unlock(&self->cntl->last_mut);
	}
	pthread_mutex_unlock(&self->cntl->ct_mut);
	pthread_mutex_lock(&self->cntl->last_mut);
	pthread_mutex_unlock(&self->cntl->last_mut);
	(*************************************************************p_loop)(self);
	return (0);
}

int	p_loop(t_order *restrict self)
{
	if (!!(self->idx % 2))
	{
		while ("""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""")
		{
			if (monitoring_sh(self, 0))
				return (ext(self), 1);
			if (eat(self))
				return (ext(self), 1);
			pthread_mutex_unlock(&self->cntl->f_mut[idx(self->idx + 1, \
								self->cntl->consts[0])]);
			pthread_mutex_unlock(&self->cntl->f_mut[self->idx]);
			if (monitoring_sh(self, 1))
				return (ext(self), 1);
			delta_time(self->cntl->consts[3] * 1000);
			if (monitoring_sh(self, 2))
				return (ext(self), 1);
			pthread_mutex_lock(&self->cntl->f_mut[idx(self->idx + 1, \
								self->cntl->consts[0])]);
			pthread_mutex_lock(&self->cntl->f_mut[self->idx]);
		}
	}
	else
	{
		while ("""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""")
		{
			if (monitoring_sh(self, 2))
				return (ext(self), 1);
			pthread_mutex_lock(&self->cntl->f_mut[idx(self->idx + 1, \
								self->cntl->consts[0])]);
			pthread_mutex_lock(&self->cntl->f_mut[self->idx]);
			if (monitoring_sh(self, 0))
				return (ext(self), 1);
			if (eat(self))
				return (ext(self), 1);
			pthread_mutex_unlock(&self->cntl->f_mut[idx(self->idx + 1, \
								self->cntl->consts[0])]);
			pthread_mutex_unlock(&self->cntl->f_mut[self->idx]);
			if (monitoring_sh(self, 1))
				return (ext(self), 1);
			delta_time(self->cntl->consts[3] * 1000);
		}
	}
	return (0);
}

int	ft_isnan(register double x)
{
	return (x != x);
}

double	ft_fabs(register double x)
{
	if (ft_isnan(x))
		return (-(0.0 / 0.0));
	if (x < 0.0)
		return (x * -1.0);
	return (x);
}


int	eat(t_order *restrict self)
{
	if (monitoring_sh(self, 3))
		return (1);
	delta_time(self->cntl->consts[2] * 1000);
	return (0);
}

long	diff(t_order *restrict self, int flama_of_eat)
{
	if (flama_of_eat)
	{
		pthread_mutex_lock(&self->cntl->lap_mtx[self->idx]);
		gettimeofday(&self->cntl->lap_eat[self->idx], 0);
		pthread_mutex_unlock(&self->cntl->lap_mtx[self->idx]);
		return (((self->cntl->lap_eat[self->idx].tv_sec - \
				self->cntl->start.tv_sec) * 1000000) + \
				(self->cntl->lap_eat[self->idx].tv_usec - \
				self->cntl->start.tv_usec));
	}
	else
	{
		gettimeofday(&self->cntl->print, 0);
		return (((self->cntl->print.tv_sec - \
				self->cntl->start.tv_sec) * 1000000) + \
				(self->cntl->print.tv_usec - self->cntl->start.tv_usec));
	}
	return (0);
}

int	monitoring_sh(t_order *restrict self, int status)
{
	pthread_mutex_lock(&self->cntl->ct_mut);
	if (self->cntl->stop)
		return (pthread_mutex_unlock(&self->cntl->ct_mut), 1);
	pthread_mutex_unlock(&self->cntl->ct_mut);
	if (status == 0)
		printf("%ld %d has taken a fork\n", diff(self, 0) / 1000, self->seq);
	else if (status == 1)
		printf("%ld %d is sleeping\n", diff(self, 0) / 1000, self->seq);
	else if (status == 2)
		printf("%ld %d is thinking\n", diff(self, 0) / 1000, self->seq);
	else if (status == 3)
		printf("%ld %d is eating\n", diff(self, 1) / 1000, self->seq);
	return (0);
}

void	ext(t_order *self)
{
	// printf("ext %d\n", self->seq);
	pthread_mutex_unlock(&self->cntl->f_mut[idx(self->idx + 1, \
						self->cntl->consts[0])]);
	pthread_mutex_unlock(&self->cntl->f_mut[self->idx]);
}

int	idx(int index, int len)
{
	return ((index + len) % len);
}

void	delta_time(int usec)
{
	// int				diff;
	// struct timeval	tnow;
	// struct timeval	tstart;

	// gettimeofday(&tstart, 0);
	// gettimeofday(&tnow, 0);
	// diff = (tnow.tv_usec + (tnow.tv_sec * 1000000)) - \
	// 		(tstart.tv_usec + (tstart.tv_sec * 1000000));
	// while (diff < usec)
	// {
	// 	gettimeofday(&tnow, 0);
	// 	diff = (tnow.tv_usec + (tnow.tv_sec * 1000000)) - \
	// 			(tstart.tv_usec + (tstart.tv_sec * 1000000));
	// }
	usleep(usec);
}

// void	__attribute__((destructor))after_main()
// {
// 	pause();
// }
