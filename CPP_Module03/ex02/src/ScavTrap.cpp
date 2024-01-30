#include "ScavTrap.hpp"
#include <string>
#include <iostream>

ScavTrap::ScavTrap(void) {
	this->setName("DEFAULT SCAV");
	this->setHp(100);
	this->setEp(50);
	this->setAd(20);
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20) {
	this->PrintDebugInfo(GREEN, "Derived constructor called!");
}

ScavTrap::~ScavTrap(void) {
	this->PrintDebugInfo(RED, "~Derived deconstructor called!");
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
