#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : _type() {
	WrongAnimal::PrintDebugInfo(GREEN, "WrongAnimal constructor called!");
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
	WrongAnimal::PrintDebugInfo(GREEN, "WrongAnimal constructor called!");
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : _type(other._type) {
	WrongAnimal::PrintDebugInfo(GREEN, "WrongAnimal copy constructor called!");
}

WrongAnimal& WrongAnimal::operator= (const WrongAnimal& other){
	WrongAnimal::PrintDebugInfo(YELLOW, "WrongAnimal copy assignment operator called!");
	WrongAnimal::_type = other._type;	
	return (*this);
}

WrongAnimal::~WrongAnimal(){
	WrongAnimal::PrintDebugInfo(RED, "~WrongAnimal deconstructor called!");
}

void		WrongAnimal::makeSound() const {
	std::cout << "WRONGAAAAAAAAAAAAAAAAANIMAL" << std::endl;
}

void	WrongAnimal::PrintDebugInfo(std::string col, std::string msg){
	std::cout << col << msg << "\033[0m\t\t" << std::endl;
}
