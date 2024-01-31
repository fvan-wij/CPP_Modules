#include "FragTrap.hpp"
#include <iostream>
#include <string>

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30) {
	this->PrintDebugInfo(GREEN, "Derived constructor called!");
}

FragTrap::~FragTrap(void) {
	this->PrintDebugInfo(RED, "~Derived deconstructor called!");
}

void	FragTrap::highFiveGuys(void) {
	std::cout << "Give me a high five! *Holds robot hand in the air*" << std::endl;
}
