/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:14:08 by ahbasara          #+#    #+#             */
/*   Updated: 2024/05/13 06:11:30 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H
# if defined(__linux__)
/* Linux. --------------------------------------------------- */
/*
**  #  include "./linux.h"
** WSL keycodes
*/
#  define O_CLOEXEC __O_CLOEXEC

# elif defined(__APPLE__)
/* OSX. --------------------------------------------------- */
/*
** #  include "./apple.h"
*/

# endif

# define RED			"\x1B[31m"
# define GREEN			"\x1B[32m"
# define YELLOW			"\x1B[33m"
# define BLUE			"\x1B[34m"
# define RESET			"\x1B[0m"

# define KB				1024
# define MB				1048576
# define GB				1073741824

# define MAX_CWD		65536

// # include "libft.h"

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_main
{
	int				has_cmd;
}		t_main;


/* FUNCTIONS */
// void	single_exe(t_main *shell, t_execd *execd);
void    a( void );


// # include "testing.h"

// void	list_cmds(t_main *data);

#endif
