#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : _fpnVal(0) {
	std::cout << "Default constructor called" << std::endl;
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

Fixed::~Fixed() {
	std::cout << "Deconstructor called" << std::endl;
}

int	Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return (_fpnVal);
}

void	Fixed::setRawBits(int const raw) {
	_fpnVal = raw;
}
