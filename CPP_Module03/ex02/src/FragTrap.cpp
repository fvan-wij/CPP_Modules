#include "FragTrap.hpp"
#include <iostream>
#include <string>

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30) {
	this->PrintDebugInfo(GREEN, "FragTrap constructor called!");
}

FragTrap::~FragTrap(void) {
	this->PrintDebugInfo(RED, "~FragTrap deconstructor called!");
}

void	FragTrap::highFiveGuys(void) {
	if (FragTrap::getHp() != 0) {
		std::cout << FragTrap::getName() <<": give me a high five! *Holds robot hand in the air*" << std::endl;
	} else {
		std::cout << FragTrap::getName() << " has no HP to do anything!" << std::endl;
	}
}
