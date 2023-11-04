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
# include "time.h"
# include "pthread.h"

// # include "testing.h"

/*
**
**
** pthread_mutex_t			count_mutex; // odd
** pthread_mutex_t			tlast_mutex; // even
*/
typedef void	t_if;

typedef struct s_cntl
{
	int																consts[5];
	pthread_t														*threat;
	pthread_mutex_t													*f_mut;
	volatile int													p_count;
	pthread_mutex_t													dead_f;
	pthread_mutex_t													ct_mut;
	pthread_mutex_t													last_mut;
	pthread_mutex_t													main_mut;
	struct timeval													*lap_eat;
	struct timeval	print;
	struct timeval													start;
	char															*p_stats;
	_Bool															flag1;
}	t_cntl;

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
	t_cntl			*cntl;
}	t_order;

#endif