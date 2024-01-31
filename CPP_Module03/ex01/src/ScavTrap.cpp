#include "ScavTrap.hpp"
#include <string>
#include <iostream>

#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"

void	ScavTrap::PrintDebugInfo(std::string col, std::string msg){
	std::cout << col << msg << "\033[0m\t\t" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20) {
	PrintDebugInfo(GREEN, "Derived constructor called!");
}

ScavTrap::~ScavTrap(void) {
	PrintDebugInfo(RED, "~Derived deconstructor called!");
}

void ScavTrap::attack(std::string name){
	std::cout << "ScavTrap: *TARGET ACQUIRED*, *SHOOTS LASER*," << " causing " << this->getAd() << " of damage to " << name << "!"<< std::endl;
}

void ScavTrap::guardGate(void) {
	_bIsGuard = !_bIsGuard;
	if (_bIsGuard) {
		std::cout << "ScavTrap " << this->getName() << " Gate keeper mode: ON" << std::endl;
	}
	else {
		std::cout << "ScavTrap " << this->getName() << " Gate keeper mode: OFF" << std::endl;
	}
};