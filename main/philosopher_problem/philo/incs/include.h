/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:14:08 by ahbasara          #+#    #+#             */
/*   Updated: 2023/11/13 18:14:19 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H
# if defined(__linux__)
/* Linux. --------------------------------------------------- */
/*
**  #  include "./linux.h"
** WSL keycodes
** #  define W 119
** #  define A 97
** #  define S 115
** #  define D 100
*/
# elif defined(__APPLE__)
/* OSX. --------------------------------------------------- */
/*
** #  include "./apple.h"
*/
#  define ARG1 "<(number_of_philosophers > 0)>"
#  define ARG2 "<time_to_die>"
#  define ARG3 "<time_to_eat>"
#  define ARG4 "<time_to_sleep>"
#  define ARG5 "[number_of_times_each_philosopher_must_eat]"
#  define RED "\x1B[31m"
#  define GREEN "\x1B[32m"
#  define YELLOW "\x1B[33m"
#  define BLUE "\x1B[34m"
#  define RESET "\x1B[0m"
# endif

// ◦timestamp_in_ms X has taken a fork
// ◦timestamp_in_ms X is eating
// ◦timestamp_in_ms X is sleeping
// ◦timestamp_in_ms X is thinking
// ◦timestamp_in_ms X died

# include "string.h"
# include "stdio.h"
# include "unistd.h"
# include "stdlib.h"
# include "sys/time.h"
# include "pthread.h"

// # include "testing.h"

/*
**
**
** pthread_mutex_t			count_mutex; // odd
** pthread_mutex_t			tlast_mutex; // even
*/
typedef void			t_if;
typedef struct timeval	t_time;
struct					s_order;

typedef struct s_cntl
{
	int									*finishes;
	pthread_mutex_t						*finishes_mutexes;
	int									consts[5];
	pthread_t							*threat;
	pthread_mutex_t						*f_mut;
	volatile int						p_count;
	pthread_mutex_t						ct_mut;
	pthread_mutex_t						last_mut;
	pthread_mutex_t						main_mut;
	pthread_mutex_t						print_mut;
	pthread_mutex_t						*lap_mtx;
	struct timeval						*lap_eat;
	struct timeval						start;
	struct timeval						print;
	_Bool								stop;
	void								(*monitoring_funs[4])(struct s_order *restrict);
}										t_cntl;

/**
 *  @struct t_order s_order
 *  @brief Filter structure 
 *	@memberof s_order::seq
 *	@var s_order::seq 
 */
typedef struct s_order
{
	int				idx;
	int				seq;
	int				eat_ct;
	t_cntl			*cntl;
}	t_order;

void	unlock(t_order *self);
void	md(t_cntl *cntl, t_time *time, int *ct);
int		run2(t_cntl *cntl, int *ct, int *diff, t_time *time);
void	run(t_cntl *cntl, int *ct, int *diff, t_time *time);
void	last_philo(t_order *self);
void	init_some2(t_cntl *cntl, t_order **tmp);
void	init_some1(t_cntl *cntl);
void	finish(t_order *self);
void	set_time_of_firs_eat_time_of_philosophers(t_order *self);
int		odd(t_order *restrict self);
int		even(t_order *restrict self);
long	diff_(t_order *restrict self);
void	ft_usleep(int time);
void	monitoring_sh_1(t_order *restrict self);
void	monitoring_sh_2(t_order *restrict self);
void	monitoring_sh_3(t_order *restrict self);
void	monitoring_sh_4(t_order *restrict self);
void	ext(t_order *self);
void		loop(t_cntl *cntl);
void	*philo(t_order *self);
int		monitoring_sh(t_order *restrict self, int status);
void	delta_time(int usec);
int		eat(t_order *restrict self);
long	diff(t_order *restrict self);
int		idx(int index, int len);
int		p_loop(t_order *restrict self);
void	init_table(t_cntl *restrict cntl);

#endif
