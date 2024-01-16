#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	_fpnVal = 0;
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
