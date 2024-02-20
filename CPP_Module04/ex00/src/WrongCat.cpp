#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	WrongCat::PrintDebugInfo(GREEN, "WrongCat constructor called!");
}

WrongCat::~WrongCat() {
	WrongCat::PrintDebugInfo(RED, "~WrongCat deconstructor called!");
}

void		WrongCat::makeSound() const {
	std::cout << "CATTTTTTTTTTTTTTTTTTTTTTTT" << std::endl;
}
