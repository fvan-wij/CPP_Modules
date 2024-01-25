#include "Fixed.hpp"
#include <cstdio>
#include <iostream>
#include <cmath>

Fixed::Fixed(){
	// std::cout << "Default constructor called" << std::endl;
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
	// std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator= (const Fixed& other){
	this->_fpnVal = other.getRawBits();
	return (*this);
}

bool Fixed::operator> (const Fixed& other) const{
	return ((this->toFloat() > other.toFloat()));
}

bool Fixed::operator< (const Fixed& other) const{
	return ((this->toFloat() < other.toFloat()));
}

bool Fixed::operator>= (const Fixed& other) const{
	return ((this->toFloat() >= other.toFloat()));
}

bool Fixed::operator<= (const Fixed& other) const{
	return ((this->toFloat() <= other.toFloat()));
}

bool Fixed::operator== (const Fixed& other) const{
	return ((this->toFloat() == other.toFloat()));
}

bool Fixed::operator!= (const Fixed& other) const{
	return ((this->toFloat() != other.toFloat()));
}

Fixed& Fixed::operator++ (){
	this->_fpnVal++;
	return (*this);
}

Fixed  Fixed::operator++ (int){

	Fixed old = *this;
	operator++();
	return (old);
}

Fixed& Fixed::operator-- (){
	this->_fpnVal--;
	return (*this);
}

Fixed  Fixed::operator-- (int){

	Fixed old = *this;
	operator--();
	return (old);
}

Fixed Fixed::operator+ (const Fixed& other){
	float result;

	result = this->toFloat() + other.toFloat();
	return (Fixed(result));
}

Fixed Fixed::operator- (const Fixed& other){
	float result;

	result = this->toFloat() - other.toFloat();
	return (Fixed(result));
}

Fixed Fixed::operator* (const Fixed& other){
	float result;

	result = this->toFloat() * other.toFloat();
	return (Fixed(result));
}

Fixed Fixed::operator/ (const Fixed& other){
	float result;

	result = this->toFloat() / other.toFloat();
	return (Fixed(result));
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
	os << obj.toFloat();
	return (os);
}

Fixed::~Fixed(){
	// std::cout << "Deconstructor called" << std::endl;
}

int	Fixed::getRawBits(void) const{
	// std::cout << "getRawBits member function called" << std::endl;
	return (_fpnVal);
}

void	Fixed::setRawBits(int const raw){
	_fpnVal = raw;
}

float	Fixed::toFloat(void) const {
	float decimalPart;
	float integerPart;

	decimalPart	= (_fpnVal & 255) / 256.0;
	integerPart = _fpnVal>>_FRACTBITS;
	return (integerPart + decimalPart);
}

int		Fixed::toInt(void) const{
	return (_fpnVal>>8);
}

Fixed& Fixed::min(Fixed& a, Fixed& b){
	if (a < b) {
		return (a);
	}
	else {
		return (b);
	}
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b){
	if (a < b) {
		return (a);
	}
	else {
		return (b);
	}
}

Fixed& Fixed::max(Fixed& a, Fixed& b){
	if (a > b) {
		return (a);
	}
	else {
		return (b);
	}
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b){
	if (a > b) {
		return (a);
	}
	else {
		return (b);
	}
}
