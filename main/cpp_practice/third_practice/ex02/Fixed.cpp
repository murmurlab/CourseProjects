#include "Fixed.hpp"

Fixed::Fixed(){
fixed_point = 0;
// cout<< "Default constructor" <<endl;
}

Fixed::Fixed( const int integer ){
fixed_point = integer << FRACTION;
// cout<< "int constructor" <<endl;
}

Fixed::Fixed( const float floatting ){
fixed_point = roundf(floatting * TOTAL_SHIFT);
// cout<< "float constructor" <<endl;
}

/* floati tamsayilastirirken 8 kere lshift yapildigi icin kesirlestirilirken
 * bolmek gerekiyor
 */
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
// cout<< "Copy constructor" <<endl;
this->fixed_point = copy.fixed_point;
}

Fixed::Fixed(const Fixed &copy){
// cout<< "Copy constructor" <<endl;
this->fixed_point = copy.fixed_point;
}

Fixed::~Fixed(){
// cout<< "Deconstructor" <<endl;
}

/* 
================================================================================
 */

bool Fixed::operator>( const Fixed &other ) {
    return this->getRawBits() > other.getRawBits();
}

bool Fixed::operator<( const Fixed &other ) {
    return this->getRawBits() < other.getRawBits();
}

bool Fixed::operator>=( const Fixed &other ) {
    return this->getRawBits() >= other.getRawBits();
}

bool Fixed::operator<=( const Fixed &other ) {
    return this->getRawBits() <= other.getRawBits();
}

bool Fixed::operator==( const Fixed &other ) {
    return this->getRawBits() == other.getRawBits();
}

bool Fixed::operator!=( const Fixed &other ) {
    return this->getRawBits() != other.getRawBits();
}



Fixed Fixed::operator-( const Fixed &other ) {
    Fixed res (this->getRawBits() - other.getRawBits());
    return res;
}

Fixed Fixed::operator+( const Fixed &other ) {
    Fixed res (this->getRawBits() + other.getRawBits());
    return res;
}
// boleceksem neden carptim?
Fixed Fixed::operator*( const Fixed &other ) {
    Fixed res;
    res.setRawBits(
        (this->getRawBits() * other.getRawBits()) / TOTAL_SHIFT
    );
    return res;
}
// carpiyorsam neden boluyorum?
Fixed Fixed::operator/( const Fixed &other ) {
    Fixed res;
    res.setRawBits(
        (this->getRawBits() * TOTAL_SHIFT) / other.getRawBits()
    );
    return res;
}



Fixed &Fixed::operator++() {
    fixed_point++;
    return *this;
}

Fixed &Fixed::operator--() {
    fixed_point--;
    return *this;
}

Fixed Fixed::operator++( int ) {
    Fixed t = *this;
    ++this->fixed_point;
    return t;
}

Fixed Fixed::operator--( int ) {
    Fixed t = *this;
    --this->fixed_point;
    return t;
}

Fixed &Fixed::max( Fixed &fp1, Fixed &fp2 ) {
    return fp1 > fp2 ? fp1 : fp2;
}

const Fixed &Fixed::max( const Fixed &fp1, const Fixed &fp2 ) {
    return fp1.getRawBits() > fp2.getRawBits() ? fp1 : fp2;
}

Fixed &Fixed::min( Fixed &fp1, Fixed &fp2 ) {
    return fp1 < fp2 ? fp1 : fp2;
}

Fixed const &Fixed::min( const Fixed &fp1, const Fixed &fp2 ) {
    return fp1.getRawBits() < fp2.getRawBits() ? fp1 : fp2;
}

/* 
================================================================================
 */


Fixed &Fixed::operator= (Fixed &assignment){
cout<< "Copy assignment" <<endl;
this->fixed_point = assignment.getRawBits();
return *this;
}

std::ostream &operator<< (std::ostream &out, const Fixed &fx){
return (out << fx.toFloat());
}

int Fixed::getRawBits( void ) const{
// cout<< "getRawBits()" <<endl;
return fixed_point;
}

void Fixed::setRawBits( int const raw ){
// cout<< "setRawBits()" <<endl;
fixed_point = raw;
}