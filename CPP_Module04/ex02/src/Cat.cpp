#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	Cat::PrintDebugInfo(GREEN, "Cat constructor called!");
	_brain = new Brain();	
}

Cat::~Cat() {
	Cat::PrintDebugInfo(RED, "~Cat deconstructor called!");
	delete _brain;
}

Cat::Cat(const Cat& other) : Animal("Cat") {
	Cat::PrintDebugInfo(GREEN, "Cat copy constructor called!");
	_brain = new Brain(*other._brain);
}

Cat& Cat::operator=(const Cat& other) {
	Cat::PrintDebugInfo(GREEN, "Cat copy assignment operator called!");
	if (this == &other) {
		return (*this);
	} else {
		delete _brain;
		_brain = new Brain(*other._brain);
		return (*this);
	}
}

void		Cat::makeSound() const {
	std::cout << "CATTTTTTTTTTTTTTTTTTTTTTTT" << std::endl;
}

Brain*	Cat::getBrain() {
	return (_brain);
}
