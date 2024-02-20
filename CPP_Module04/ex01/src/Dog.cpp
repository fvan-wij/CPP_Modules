#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	Dog::PrintDebugInfo(GREEN, "Dog constructor called!");
	_brain = new Brain();	
}

Dog::~Dog(){
	Dog::PrintDebugInfo(RED, "~Dog deconstructor called!");
	delete _brain;
}

void		Dog::makeSound() const {
	std::cout << "DOOOOOOOOOOOOOOOOOGGGGGGGGGGGGGGGGGGGGGGGG" << std::endl;
}

