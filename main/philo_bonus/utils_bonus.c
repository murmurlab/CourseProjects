/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 05:47:28 by ahbasara          #+#    #+#             */
/*   Updated: 2024/12/11 05:56:55 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_timestamp	get_timestamp(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) != 0)
		return (0);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_usleep(t_timestamp ms)
{
	t_timestamp	start;

	start = get_timestamp();
	while ((get_timestamp() - start) < ms)
		usleep(100);
}

void	philo_msg(t_scheduler *scheduler, char *msg)
{
	t_timestamp	time;

	sem_wait(scheduler->print);
	am_i_dead(scheduler);
	time = get_timestamp();
	printf("%llu %d %s\n", time - scheduler->start, scheduler->i + 1, msg);
	sem_post(scheduler->print);
}

void	yes_i_am_dead(t_scheduler *scheduler)
{
	printf("%llu %i died\n", get_timestamp() - \
		scheduler->start, scheduler->i + 1);
	exit(1);
}

void	am_i_dead(t_scheduler *scheduler)
{
	t_timestamp const	time = get_timestamp();

	if (time - scheduler->last_meal_time > scheduler->time_to_die)
		yes_i_am_dead(scheduler);
}
