#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	_fpnVal = 0;
}

Fixed::Fixed(const int integer){
	std::cout << "Integer constructor called" << std::endl;
	_fpnVal = (integer<<_FRACTBITS);
}

Fixed::Fixed(const float floatingPointNumber){
	std::cout << "Float constructor called" << std::endl;

	float fpRepresentation = floatingPointNumber * (1<<_FRACTBITS);
	this->setRawBits(roundf(fpRepresentation));
}

Fixed::Fixed(const Fixed& other){
	*this = other;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator= (const Fixed& other){
	this->_fpnVal = other.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
	os << obj.toFloat();
	return (os);
}

Fixed::~Fixed(){
	std::cout << "Deconstructor called" << std::endl;
}

int	Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called" << std::endl;
	return (_fpnVal);
}

void	Fixed::setRawBits(int const raw){
	_fpnVal = raw;
}

float	Fixed::toFloat(void) const {
	// Do ANDOR operation on _fpnVal, to figure out value of the first 8 bits, save in variable, transnlate to decimal == decimalPart;
	float decimalPart = (_fpnVal & 255) / 256.0;
	// Bitshift by 8 bits == integerPart
	float integerPart = _fpnVal>>8;
	// return integerPart + decimalPart;
	return (integerPart + decimalPart);
}

int		Fixed::toInt(void) const{
	return (_fpnVal>>8);
}

