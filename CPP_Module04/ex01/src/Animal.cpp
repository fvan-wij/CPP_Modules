#include "Animal.hpp"
#include <iostream>

Animal::Animal() : _type() {
	Animal::PrintDebugInfo(GREEN, "Animal constructor called!");
}

Animal::Animal(std::string type) : _type(type) {
	Animal::PrintDebugInfo(GREEN, "Animal constructor called!");
}

Animal::Animal(const Animal& other) : _type(other._type) {
	Animal::PrintDebugInfo(GREEN, "Animal copy constructor called!");
}

Animal& Animal::operator= (const Animal& other){
	Animal::PrintDebugInfo(YELLOW, "Animal copy assignment operator called!");
	Animal::_type = other._type;	
	return (*this);
}

Animal::~Animal(){
	Animal::PrintDebugInfo(RED, "~Animal deconstructor called!");
}

void		Animal::makeSound() const {
	std::cout << "AAAAAAAAAAAAAAAAANIMAL" << std::endl;
}

void	Animal::PrintDebugInfo(std::string col, std::string msg){
	std::cout << col << msg << "\033[0m\t\t" << std::endl;
}

std::string	Animal::getType() const {
	return (_type);
}

void	Animal::setType(std::string type) {
	_type = type;
}

