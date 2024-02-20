#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	Dog::PrintDebugInfo(GREEN, "Dog constructor called!");
}

Dog::~Dog(){
	Dog::PrintDebugInfo(RED, "~Dog deconstructor called!");
}

void		Dog::makeSound() const {
	std::cout << "DOOOOOOOOOOOOOOOOOGGGGGGGGGGGGGGGGGGGGGGGG" << std::endl;
}

