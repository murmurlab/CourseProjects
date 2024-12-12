/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 05:48:23 by ahbasara          #+#    #+#             */
/*   Updated: 2024/12/11 05:56:52 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init_scheduler_2(t_scheduler *scheduler)
{
	sem_unlink("forks");
	sem_unlink("print");
	sem_unlink("queue_take_forks");
	sem_unlink("full_philos");
	scheduler->full_philos = sem_open("full_philos", O_CREAT, \
		0644, scheduler->philo_count);
	scheduler->print = sem_open("print", O_CREAT, \
		0644, 1);
	scheduler->forks = sem_open("forks", O_CREAT, 0644, \
		scheduler->philo_count);
	scheduler->queue_take_forks = sem_open("queue_take_forks", \
		O_CREAT, 0644, 1);
	scheduler->pids = malloc(sizeof(int) * scheduler->philo_count);
	scheduler->start = get_timestamp();
	scheduler->last_meal_time = get_timestamp();
}

int	init_scheduler_1(t_scheduler *scheduler, int argc, char const *argv[])
{
	scheduler->eat[INFINITE] = &until_the_end;
	scheduler->eat[FINITE] = &until_satisfied;
	scheduler->philo_count = atoi(argv[1]);
	scheduler->time_to_die = atoi(argv[2]);
	scheduler->time_to_eat = atoi(argv[3]);
	scheduler->time_to_sleep = atoi(argv[4]);
	if (argc != 6)
		scheduler->dinner_type = INFINITE;
	else
	{
		scheduler->meal_count = atoi(argv[5]);
		if (scheduler->meal_count < 1)
		{
			printf("<0 meal count is not allowed\n");
			exit((free(scheduler->pids), 1));
		}
		scheduler->dinner_type = FINITE;
	}
	init_scheduler_2(scheduler);
	return (0);
}
