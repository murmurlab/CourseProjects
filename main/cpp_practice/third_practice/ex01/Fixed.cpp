#include "Fixed.hpp"

Fixed::Fixed(){
fixed_point = 0;
cout<< "Default constructor" <<endl;
}

Fixed::Fixed( const int integer ){
fixed_point = integer << FRACTION;
cout<< "int constructor" <<endl;
}

Fixed::Fixed( const float floatting ){
fixed_point = roundf(floatting * TOTAL_SHIFT);
cout<< "float constructor" <<endl;
}

float Fixed::toFloat( void ) const{
float   f;

f = fixed_point;
f /= TOTAL_SHIFT;
return (f);
}

int Fixed::toInt( void ) const{
return (fixed_point / TOTAL_SHIFT);
}

Fixed::Fixed(Fixed &copy){
cout<< "Copy constructor" <<endl;
this->fixed_point = copy.fixed_point;
}

Fixed::~Fixed(){
cout<< "Deconstructor" <<endl;
}

Fixed &Fixed::operator= (Fixed &assignment){
cout<< "Copy assignment" <<endl;
this->fixed_point = assignment.getRawBits();
return *this;
}

std::ostream &operator<< (std::ostream &out, const Fixed &fx){
return (out << fx.toFloat());
}

int Fixed::getRawBits( void ) const{
cout<< "getRawBits()" <<endl;
return fixed_point;
}

void Fixed::setRawBits( int const raw ){
cout<< "setRawBits()" <<endl;
fixed_point = raw;
}