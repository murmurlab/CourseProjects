/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 02:42:30 by ahbasara          #+#    #+#             */
/*   Updated: 2024/12/11 05:59:09 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <semaphore.h>
# include <sys/wait.h>
# include <stddef.h>
# include <sys/time.h>
# include <signal.h>
# include <fcntl.h>

# define ARG1	"number_of_philosophers"
# define ARG2	"time_to_die"
# define ARG3	"time_to_eat"
# define ARG4	"time_to_sleep"
# define ARG5	"number_of_times_each_philosopher_must_eat"

typedef unsigned long long	t_timestamp;

typedef enum e_dinner_type
{
	INFINITE,
	FINITE
}	t_dinner_type;

struct						s_scheduler;

typedef void				(*t_funs)(struct s_scheduler *);

typedef struct s_scheduler
{
	// void			(*(eat[2]))(struct s_scheduler *scheduler);
	t_funs			eat[2];
	t_timestamp		start;

	t_dinner_type	dinner_type;
	int				philo_count;
	t_timestamp		time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meal_count;

	t_timestamp		last_meal_time;

	// sem_t		*somenone_rip;
	sem_t			*forks;
	sem_t			*queue_take_forks;
	sem_t			*print;
	sem_t			*full_philos;

	int				*pids;
	int				exit_code;

	int				i;
}	t_scheduler;

void		until_the_end(t_scheduler *scheduler);
void		until_satisfied(t_scheduler *scheduler);
void		killall_philo(t_scheduler *scheduler);
void		philo_msg(t_scheduler *scheduler, char *msg);
void		ft_usleep(t_timestamp ms);
int			init_scheduler_1(t_scheduler *scheduler, int argc,
				char const *argv[]);
t_timestamp	get_timestamp(void);
void		am_i_dead(t_scheduler *scheduler);

// void __attribute__((destructor))after_main()
// {
// 	system("leaks philo_bonus");
// 	// cout << "rst" << endl;
// 	// __lsan_do_leak_check();
// 	// __lsan_do_recoverable_leak_check();
// }

#endif
