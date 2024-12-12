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
    Fixed(const Fixed &copy);
    ~Fixed();

    int toInt( void ) const;
    float toFloat( void ) const;
    Fixed(const int integer);
    Fixed(const float floatting);

    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);
    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);

    Fixed &operator= (Fixed &assignment);

    Fixed	operator-(const Fixed &other);
    Fixed	operator+(const Fixed &other);
    Fixed	operator*(const Fixed &other);
    Fixed	operator/(const Fixed &other);

    Fixed   operator++(int);
    Fixed	&operator++();
    Fixed	operator--(int);
    Fixed	&operator--();

    bool    operator==(const Fixed &other);
    bool    operator!=(const Fixed &other);
    bool	operator>(const Fixed &other);
    bool	operator<(const Fixed &other);
    bool	operator>=(const Fixed &other);
    bool	operator<=(const Fixed &other);

    int getRawBits( void ) const;
    void setRawBits( int const raw );
};

std::ostream &operator << (std::ostream &out, const Fixed &fx);


#endif
