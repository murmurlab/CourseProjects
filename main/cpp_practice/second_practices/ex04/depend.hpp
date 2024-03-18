/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   depend.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:14:08 by ahbasara          #+#    #+#             */
/*   Updated: 2024/03/18 17:39:05 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DEPEND_H
# define DEPEND_H
# if defined(__linux__)
/* Linux. --------------------------------------------------- */

# elif defined(__APPLE__)
/* OSX. --------------------------------------------------- */

# endif

#include <iostream>
#include <fstream>

# define RED				"\x1B[31m"
# define GREEN				"\x1B[32m"
# define YELLOW				"\x1B[33m"
# define BLUE				"\x1B[34m"
# define RESET				"\x1B[0m"

# define BUFFER_SIZE        10

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::ofstream;
using std::ifstream;
using std::ios;

#endif
