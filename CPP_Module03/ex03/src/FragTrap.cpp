#include "FragTrap.hpp"
#include <iostream>
#include <string>

FragTrap::FragTrap(void) {
	FragTrap::PrintDebugInfo(GREEN, "FragTrap consructor called!");
	ClapTrap::setName("Default Name");
	ClapTrap::setHp(100);
	ClapTrap::setEp(100);
	ClapTrap::setAd(30);
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30) {
	ClapTrap::PrintDebugInfo(GREEN, "FragTrap constructor called!");
}

FragTrap::~FragTrap(void) {
	ClapTrap::PrintDebugInfo(RED, "~FragTrap deconstructor called!");
}

void	FragTrap::highFiveGuys(void) {
	std::cout << "Give me a high five! *Holds robot hand in the air*" << std::endl;
}
