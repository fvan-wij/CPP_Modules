#include "FragTrap.hpp"
#include <iostream>
#include <string>

FragTrap::FragTrap(std::string name) {
	this->PrintDebugInfo(GREEN, "Derived-derived constructor called!");
	this->setName(name);
	this->setHp(100);
	this->setEp(100);
	this->setAd(30);
}

FragTrap::~FragTrap(void) {
	this->PrintDebugInfo(RED, "~Derived-derived deconstructor called!");
}

void	FragTrap::highFiveGuys(void) {
	std::cout << "Give me a high five! *Holds robot hand in the air*" << std::endl;
}
