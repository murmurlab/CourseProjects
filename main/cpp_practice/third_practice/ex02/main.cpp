#include <iostream>
#include "Fixed.hpp"

int main( void ) {
float aaa = 153.223f;
aaa--;
cout << aaa << endl;
    
Fixed a(153.89999999f);
Fixed b( 123.123f );
Fixed c;
c = b;

std::cout << a.getRawBits() << std::endl;
std::cout << b.getRawBits() << std::endl;
std::cout << c.getRawBits() << std::endl;
cout << c.toFloat() << endl;
cout << c.toInt() << endl;
cout << "||" << (a - b) << "||" << (a) << "||" << endl;


Fixed a1;
Fixed const b1( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a1 << std::endl;
std::cout << ++a1 << std::endl;
std::cout << a1 << std::endl;
std::cout << a1++ << std::endl;
std::cout << a1 << std::endl;
std::cout << b1 << std::endl;
std::cout << Fixed::max( a1, b1 ) << std::endl;

return 0;
}