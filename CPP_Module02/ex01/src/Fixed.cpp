#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _fpnVal(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int integer) : _fpnVal(integer<<_FRACTBITS) {
	std::cout << "Integer constructor called" << std::endl;
}

Fixed::Fixed(const float floatingPointNumber) {
	std::cout << "Float constructor called" << std::endl;
	float fpRepresentation = floatingPointNumber * (1<<_FRACTBITS);
	this->setRawBits(roundf(fpRepresentation));
}

Fixed::Fixed(const Fixed& other) : _fpnVal(other._fpnVal) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator= (const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &other) {
		return (*this);
	}
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

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (_fpnVal);
}

void	Fixed::setRawBits(int const raw) {
	_fpnVal = raw;
}

float	Fixed::toFloat(void) const {
	float decimalPart;
	float integerPart;

	decimalPart	= (_fpnVal & 255) / 256.0;
	integerPart = _fpnVal>>_FRACTBITS;
	return (integerPart + decimalPart);
}

int		Fixed::toInt(void) const {
	return (_fpnVal>>8);
}

