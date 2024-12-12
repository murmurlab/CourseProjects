/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:14:08 by ahbasara          #+#    #+#             */
/*   Updated: 2024/03/23 15:01:51 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_H
# define FIXED_H
# if defined(__linux__)
/* Linux. --------------------------------------------------- */

# elif defined(__APPLE__)
/* OSX. --------------------------------------------------- */

# endif

# define RED				"\x1B[31m"
# define GREEN				"\x1B[32m"
# define YELLOW				"\x1B[33m"
# define BLUE				"\x1B[34m"
# define RESET				"\x1B[0m"

# define FRACTION           8
# define TOTAL_SHIFT        (1 << FRACTION)

#include <iostream>
#include <cmath>

using std::cout;
using std::cerr;
using std::endl;
using std::string;

class Fixed
{
private:
    int                 fixed_point;
    static const int    fractional = FRACTION;
public:
    Fixed();
    Fixed(Fixed &copy);
    ~Fixed();

    Fixed &operator= (Fixed &assignment);

    int toInt( void ) const;
    float toFloat( void ) const;
    Fixed(const int integer);
    Fixed(const float floatting);
    int getRawBits( void ) const;
    void setRawBits( int const raw );
};

std::ostream &operator << (std::ostream &out, const Fixed &fx);


#endif
