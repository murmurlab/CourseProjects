/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:14:08 by ahbasara          #+#    #+#             */
/*   Updated: 2023/11/16 23:47:08 by ahbasara         ###   ########.fr       */
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

// # include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
// # include <sys/stat.h>
// # include <readline/readline.h>
// # include <readline/history.h>
// # include <fcntl.h>
// # include <sys/wait.h>
// # include <signal.h>
// # include <sys/ioctl.h>
// # include <termios.h>
// # include <errno.h>
// # include <sys/types.h>
// # include <dirent.h>

// # include "testing.h"

/*
**
** pthread_mutex_t			count_mutex; // odd
** pthread_mutex_t			tlast_mutex; // even
*/
typedef void			t_if;

/**
 *  @struct t_order s_order
 *  @brief Filter structure 
 *	@memberof s_order::seq
 *	@var s_order::seq 
 */

#endif
