/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 02:19:58 by ahbasara          #+#    #+#             */
/*   Updated: 2024/12/11 05:58:04 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	until_satisfied(t_scheduler *scheduler)
{
	scheduler->meal_count--;
	if (scheduler->meal_count == 0)
	{
		exit(0);
		sem_wait(scheduler->full_philos);
		scheduler->dinner_type = INFINITE;
	}
}

void	until_the_end(t_scheduler *scheduler)
{
	(void)scheduler;
}

void	philo(t_scheduler *scheduler)
{
	free(scheduler->pids);
	while (1)
	{
		philo_msg(scheduler, "is thinking");
		sem_wait(scheduler->queue_take_forks);
		sem_wait(scheduler->forks);
		philo_msg(scheduler, "has taken a fork");
		sem_wait(scheduler->forks);
		philo_msg(scheduler, "has taken a fork");
		sem_post(scheduler->queue_take_forks);
		scheduler->last_meal_time = get_timestamp();
		philo_msg(scheduler, "is eating");
		ft_usleep(scheduler->time_to_eat);
		sem_post(scheduler->forks);
		sem_post(scheduler->forks);
		scheduler->eat[scheduler->dinner_type](scheduler);
		philo_msg(scheduler, "is sleeping");
		ft_usleep(scheduler->time_to_sleep);
		philo_msg(scheduler, "is thinking");
	}
}

void	killall_philo(t_scheduler *scheduler)
{
	while (--scheduler->i >= 0)
		kill(scheduler->pids[scheduler->i], SIGKILL);
}

// void	leak(void)
// {
// 	system("leaks philo_bonus");
// }

int	main(int argc, char const *argv[])
{
	t_scheduler *const	scheduler = &(t_scheduler){0};

	if (argc < 5 || argc > 6 || atoi(argv[1]) < 1)
		return (printf("usage: %s %s %s %s %s %s\n",
				argv[0], ARG1, ARG2, ARG3, ARG4, ARG5), 1);
	init_scheduler_1(scheduler, argc, argv);
	while (scheduler->i < scheduler->philo_count)
	{
		scheduler->pids[scheduler->i] = fork();
		if (scheduler->pids[scheduler->i] == 0)
			philo(scheduler);
		else
			scheduler->i++;
	}
	while (wait(&scheduler->exit_code) > 0)
	{
		if (WIFSIGNALED(scheduler->exit_code))
			continue ;
		if (scheduler->exit_code != 0)
			killall_philo(scheduler);
	}
	return (free(scheduler->pids), 0);
}
