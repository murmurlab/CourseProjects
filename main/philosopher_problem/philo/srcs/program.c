/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 21:30:20 by ahbasara          #+#    #+#             */
/*   Updated: 2023/11/02 19:31:20 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"
#include <sys/time.h>

/**
 * can do be main:
 * while(1)
 *	p_ct_mut_lock;
 *	p_count == consts[0]: 
 *		unlock_mutex_bulk();
 *		break ;
 *						?
 *		p_ct_mut_unlock;
 * alternatively
 */

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

void	monitoring_sh(t_order *restrict self, int status);
void	delta_time(int usec);

void	eat(t_order *restrict self)
{
	monitoring_sh(self, 3);
	delta_time(self->cntl->consts[2] * 1000);
}

long	diff(t_order *restrict self, int flama_of_eat)
{

	if (flama_of_eat)
	{
		gettimeofday(&self->cntl->lap_eat[self->idx], 0);
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

void	monitoring_sh(t_order *restrict self, int status)
{
	if (status == 0)
		printf("%ld %d has taken a fork\n", diff(self, 0) / 1000, self->seq);
	else if (status == 1)
		printf("%ld %d is sleeping\n", diff(self, 0) / 1000, self->seq);
	else if (status == 2)
		printf("%ld %d is thinking\n", diff(self, 0) / 1000, self->seq);
	else if (status == 3)
		printf("%ld %d is eating\n", diff(self, 1) / 1000, self->seq);
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

void	p_loop(t_order *restrict self)
{
	while ("""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""")
	{
		(t_if)(!!(self->idx % 2) &&
		(
			monitoring_sh(self, 0),
			eat(self),
			pthread_mutex_unlock(&self->cntl->f_mut[idx(self->idx + 1, \
								self->cntl->consts[0])]),
			pthread_mutex_unlock(&self->cntl->f_mut[self->idx]),
			monitoring_sh(self, 1),
			delta_time(self->cntl->consts[3] * 1000),
			monitoring_sh(self, 2),
			pthread_mutex_lock(&self->cntl->f_mut[idx(self->idx + 1, \
								self->cntl->consts[0])]),
			pthread_mutex_lock(&self->cntl->f_mut[self->idx])
		));
		(t_if)(!(self->idx % 2) &&
		(
			monitoring_sh(self, 2),
			pthread_mutex_lock(&self->cntl->f_mut[idx(self->idx + 1, \
								self->cntl->consts[0])]),
			pthread_mutex_lock(&self->cntl->f_mut[self->idx]),
			monitoring_sh(self, 0),
			eat(self),
			pthread_mutex_unlock(&self->cntl->f_mut[idx(self->idx + 1, \
								self->cntl->consts[0])]),
			pthread_mutex_unlock(&self->cntl->f_mut[self->idx]),
			monitoring_sh(self, 1),
			(delta_time(self->cntl->consts[3] * 1000), 1)
		));
	}
}

void	*philo(
	void *self
)
{
	// printf("lap eat ilk %p(((\n", ((t_order *)self)->cntl->lap_eat);
	// printf("normal %d %d\n", ((t_order *)self)->idx, ((t_order *)self)->seq);
	pthread_mutex_init((((t_order *)self))->cntl->f_mut + (((t_order *)self))->idx, 0);
	if ((((t_order *)self))->idx % 2)
	{
		pthread_mutex_lock(&(((t_order *)self))->cntl->f_mut[(((((t_order *)self))->idx + 1) + (((t_order *)self))->cntl->consts[0]) % (((t_order *)self))->cntl->consts[0]]);
		pthread_mutex_lock(&(((t_order *)self))->cntl->f_mut[(((t_order *)self))->idx]);
	}
	pthread_mutex_lock(&(((t_order *)self))->cntl->ct_mut);
	(((t_order *)self))->cntl->p_count++;
	// printf("philo %d is counted to %d""\n",
	// 	(((t_order *)self))->cntl->p_count,
	// 	(((t_order *)self))->cntl->consts[0]);
	// printf("12381293712983712983712983791---------   th  %d    ----------sstiaernstzzzzzzz %p\n", (((t_order *)self))->idx, (((t_order *)self))->cntl->lap_eat);
	if ((((t_order *)self))->cntl->p_count == (((t_order *)self))-> \
		cntl->consts[0])
	{
		printf("unlock last_mut\n");
		pthread_mutex_unlock(&(((t_order *)self))->cntl->main_mut);
		pthread_mutex_unlock(&(((t_order *)self))->cntl->last_mut);
		gettimeofday(&(((t_order *)self))->cntl->start, 0);
	}
	// printf("constslasarsirenarsienarisen---------   th  %d    ----------sstiaernstzzzzzzz %p\n", (((t_order *)self))->idx, (((t_order *)self))->cntl->lap_eat);
	pthread_mutex_unlock(&(((t_order *)self))->cntl->ct_mut);
	pthread_mutex_lock(&(((t_order *)self))->cntl->last_mut);
	pthread_mutex_unlock(&(((t_order *)self))->cntl->last_mut);
	// printf("!%d!\n", (((t_order *)self))->idx);
	// printf("lap eat son %p<\n", ((t_order *)self)->cntl->lap_eat);
	// printf("ret %d\n", gettimeofday(((t_order *)self)->cntl->lap_eat + 1, 0));
	// printf("uuu%lduuu\n", ((t_order *)self)->cntl->lap_eat[1].tv_sec);
	// printf("philo %d is free!\n", (((t_order *)self))->idx);
	(*************************************************************p_loop)(((t_order *)self));
	return (0);
}

void	loop(t_cntl *cntl)
{
	int				ct;
	int				dead;
	struct timeval	time;
	int				diff;

	dead = 0;
	ct = 0;
	while (!dead)
	{
		while (ct < cntl->consts[0])
		{
			gettimeofday(&time, 0);
			diff = ((time.tv_sec - cntl->lap_eat[ct].tv_sec) * 1000000) + \
					((time.tv_usec - cntl->lap_eat[ct].tv_usec));
			if (diff > \
				(cntl->consts[1] * 1000))
			{
				dead = '???\\';
				printf("%ld %ld\n%d %d\n%d\n", time.tv_sec, cntl->lap_eat[ct].tv_sec, time.tv_usec, cntl->lap_eat[ct].tv_usec, diff);
				break ;
			}
			else
				ct++;
		}
		ct = 0;
	}
}

void	init_cntl(t_cntl *cntl)
{
	while (1)
	{
		while (1)
		{
			while (1)
			{
				while (1)
				{
					while (1)
					{
						while (1)
						{
							while (1)
							{
								while (1)
								{
									return (loop(cntl));
								}
							}
						}
					}
				}
			}
		}
	}
}

/* 
** @brief init_table dfdf
** @param sd: 
** @return at
** 85: arsr
 */
void	init_table(t_cntl *restrict cntl)
{
	register int		_;
	t_order				**tmp;

	(_) = (0 - 0 - 0 - 0 - 0 - 0 - 000000000000000 - 0 - 0 - 0 - 0 - 0 - 0 - 0);
	tmp = malloc(sizeof(t_order *) * cntl->consts[0]);
	cntl->threat = malloc(sizeof(pthread_t) * cntl->consts[0]);
	cntl->f_mut = malloc(sizeof(pthread_mutex_t) * \
								cntl->consts[0]);
	cntl->p_stats = malloc(sizeof(char) * cntl->consts[0]);
	cntl->lap_eat = malloc(sizeof(struct timeval) * cntl->consts[0]);
	cntl->p_count = '\0';
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
		// printf("rrrr%drrrr \n", _);
		tmp[_]->cntl = cntl;
		_++;
	}
	// printf("_ %d\n", _);
	while (--(_) > -1)
	{
		// printf("git>>>>>> %d\n", _);
		// printf("------------------------------------- %d\n", tmp[_]->cntl->consts[1]);
		// printf("__%p__ \n", tmp[_]->cntl->lap_eat);
		pthread_create(cntl->threat + (_), 0, philo, tmp[_]);
	}
	printf("main wait\n");
	pthread_mutex_lock(&cntl->main_mut);
	printf("main cycle\n");
	init_cntl(cntl);
	// while (--(_) > -1)
		// pthread_detach(*(cntl->threat + (_)));
	// pause();
}



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
	// init_cntl();
	// start_loop(&cntl);
	return (""[0]);
}

// void	__attribute__((destructor))after_main()
// {
// 	pause();
// }
