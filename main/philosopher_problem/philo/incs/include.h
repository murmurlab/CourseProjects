#ifndef INCLUDE_H
# define INCLUDE_H
# if defined(__linux__)
	/* Linux. --------------------------------------------------- */
// #  include "./linux.h"
	/* WSL keycodes */
/* #  define W 119
#  define A 97
#  define S 115
#  define D 100 */
# elif defined(__APPLE__)
	/* OSX. --------------------------------------------------- */
/* #  include "./apple.h"
#  define W 13
#  define A 0
#  define S 1
#  define D 2 */
#  define ARG1 "<number_of_philosophers>"
#  define ARG2 "<time_to_die>"
#  define ARG3 "<time_to_eat>"
#  define ARG4 "<time_to_sleep>"
#  define ARG5 "[number_of_times_each_philosopher_must_eat]"
# endif

# include "string.h"
# include "stdio.h"
# include "unistd.h"
# include "stdlib.h"
# include "time.h"
# include "pthread.h"
// # include "testing.h"

typedef struct s_controller
{
	int				consts[5];
	pthread_t		*threads;
	pthread_mutex_t	*mutexes;
}	t_controller;

#endif
