#include <iostream>
#include "Fixed.hpp"

int main( void ) {
Fixed a(235.2444213f);
Fixed b( a );
Fixed c;
c = b;
std::cout << a.getRawBits() << std::endl;
std::cout << b.getRawBits() << std::endl;
std::cout << c.getRawBits() << std::endl;
cout << c.toFloat() << endl;
cout << c.toInt() << endl;
cout << c << "|" << c << endl;
return 0;
}