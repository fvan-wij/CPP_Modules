#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	Cat::PrintDebugInfo(GREEN, "Cat constructor called!");
}

Cat::~Cat() {
	Cat::PrintDebugInfo(RED, "~Cat deconstructor called!");
}

void		Cat::makeSound() const {
	std::cout << "CATTTTTTTTTTTTTTTTTTTTTTTT" << std::endl;
}
