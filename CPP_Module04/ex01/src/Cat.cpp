#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	Cat::PrintDebugInfo(GREEN, "Cat constructor called!");
	_brain = new Brain();	
}

Cat::~Cat() {
	Cat::PrintDebugInfo(RED, "~Cat deconstructor called!");
	delete _brain;
}

void		Cat::makeSound() const {
	std::cout << "CATTTTTTTTTTTTTTTTTTTTTTTT" << std::endl;
}

