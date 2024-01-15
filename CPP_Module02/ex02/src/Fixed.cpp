#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	_fpnVal = 0;
}

Fixed::Fixed(const int integer){
	_fpnVal = (integer<<_FRACTBITS);
}

Fixed::Fixed(const float floatingPointNumber){
	float 	decimalPart = floatingPointNumber - (int)floatingPointNumber;
	int 	integerPart = floatingPointNumber - decimalPart;
	int 	fractionalRepresentation = 0;

	for (size_t i = 0; i < _FRACTBITS; i++){
		decimalPart *= 2;
		if (decimalPart == 1.0){
			fractionalRepresentation += (1<<(7-i));
			break;
		}
		else if ((decimalPart - (decimalPart - (int)decimalPart)) == 1.0){
			fractionalRepresentation += (1<<(7-i));
			decimalPart -= 1;
		}
	}
	integerPart = integerPart<<8;
	this->setRawBits(fractionalRepresentation + integerPart);
}

Fixed::Fixed(const Fixed& other){
	*this = other;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator= (const Fixed& other){
	this->_fpnVal = other.getRawBits();
	return (*this);
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
