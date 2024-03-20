#include "Fixed.hpp"

Fixed::Fixed(){
fixed_point = 0;
cout<< "Default constructor" <<endl;
}

Fixed::Fixed(Fixed &copy){
cout<< "Copy constructor" <<endl;
}

Fixed::~Fixed(){
cout<< "Deconstructor" <<endl;
}

Fixed Fixed::operator=(Fixed assignment){
cout<< "Copy assignment" <<endl;
}

int Fixed::getRawBits( void ) const{
cout<< "getRawBits()" <<endl;
return fixed_point;
}

void Fixed::setRawBits( int const raw ){
cout<< "setRawBits()" <<endl;
fixed_point = raw;
}