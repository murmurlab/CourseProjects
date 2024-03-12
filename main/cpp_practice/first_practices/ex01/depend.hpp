/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   depend.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:14:08 by ahbasara          #+#    #+#             */
/*   Updated: 2024/03/11 10:59:56 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DEPEND_H
# define DEPEND_H
# if defined(__linux__)
/* Linux. --------------------------------------------------- */

# elif defined(__APPLE__)
/* OSX. --------------------------------------------------- */

# endif

# include <iostream>

# define RED				"\x1B[31m"
# define GREEN				"\x1B[32m"
# define YELLOW				"\x1B[33m"
# define BLUE				"\x1B[34m"
# define RESET				"\x1B[0m"

%: define PREFIX				"Enter the "
%: define SUFFIX				"> "

# define PROMT_FNAME		PREFIX "first name" SUFFIX
# define PROMT_LNAME		PREFIX "last name" SUFFIX
# define PROMT_NNAME		PREFIX "nick name" SUFFIX
# define PROMT_PHONE		PREFIX "phone number" SUFFIX
# define PROMT_SEC			PREFIX "secret darkest secret" SUFFIX

# define INVALID_SELECTION	"Invalid command"

# define SUCC_ADD			"The contact added"
# define SUCC_SEARCH		"Results"
# define SUCC_EXIT			"bYe bYe"


using std::cout;
using std::cin;
using std::endl;
using std::string;

typedef enum option {
	ADD,
	SEARCH,
	EXIT,
	DEFAULT
}   t_option;

/**
 *  @struct t_order s_order
 *  @brief Filter structure 
 *	@memberof s_order::seq
 *	@var s_order::seq 
 */

#endif
