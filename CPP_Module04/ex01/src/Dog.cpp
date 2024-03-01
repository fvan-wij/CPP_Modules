#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	Dog::PrintDebugInfo(GREEN, "Dog constructor called!");
	_brain = new Brain();	
}

Dog::~Dog() {
	Dog::PrintDebugInfo(RED, "~Dog deconstructor called!");
	delete _brain;
}

Dog::Dog(const Dog& other) : Animal("Dog") {
	Dog::PrintDebugInfo(GREEN, "Dog copy constructor called!");
	_brain = new Brain(*other._brain);
}

Dog& Dog::operator=(const Dog& other) {
	Dog::PrintDebugInfo(GREEN, "Dog copy assignment operator called!");
	if (this == &other) {
		return (*this);
	} else {
		delete _brain;
		_brain = new Brain (*other._brain);
		return (*this);
	}
}

void		Dog::makeSound() const {
	std::cout << "DOOOOOOOOOOOOOOOOOGGGGGGGGGGGGGGGGGGGGGGGG" << std::endl;
}

Brain*	Dog::getBrain() {
	return (_brain);
}
