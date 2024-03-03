/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:14:08 by ahbasara          #+#    #+#             */
/*   Updated: 2024/02/29 03:31:21 by ahbasara         ###   ########.fr       */
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
#  define O_CLOEXEC __O_CLOEXEC

# elif defined(__APPLE__)
/* OSX. --------------------------------------------------- */
/*
** #  include "./apple.h"
*/

# endif

#include <iostream>

# define RED			"\x1B[31m"
# define GREEN			"\x1B[32m"
# define YELLOW			"\x1B[33m"
# define BLUE			"\x1B[34m"
# define RESET			"\x1B[0m"

extern int		g_qsignal;

/**
 *  @struct t_order s_order
 *  @brief Filter structure 
 *	@memberof s_order::seq
 *	@var s_order::seq 
 */

typedef struct s_export
{
	void		*arg;
	char		*discriminant;
	int			err;
	int			gerr;
	char		*to_set;
	char		validate;
}		t_export;

class Matrix
{
    // ...
    friend Vector operator*(const Matrix&, const Vector&);
};

/* FUNCTIONS */
int		i_space(char character);

// # include "testing.h"

// void	list_cmds(t_main *data);

#endif
