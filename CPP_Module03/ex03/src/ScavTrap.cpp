#include "ScavTrap.hpp"
#include <string>
#include <iostream>

ScavTrap::ScavTrap(void) {
	ClapTrap::PrintDebugInfo(GREEN, "ScavTrap constructor called!");
	ClapTrap::setName("DEFAULT SCAV");
	ClapTrap::setHp(100);
	ClapTrap::setEp(50);
	ClapTrap::setAd(20);
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20) {
	ClapTrap::PrintDebugInfo(GREEN, "ScavTrap constructor called!");
}

ScavTrap::~ScavTrap(void) {
	ClapTrap::PrintDebugInfo(RED, "~ScavTrap constructor called!");
}

void ScavTrap::attack(std::string name){
	std::cout << "ScavTrap: *TARGET ACQUIRED*, *SHOOTS LASER*," << " causing " << ScavTrap::getAd() << " of damage to " << name << "!"<< std::endl;
}

void ScavTrap::guardGate(void) {
	_bIsGuard = !_bIsGuard;
	if (_bIsGuard) {
		std::cout << "ScavTrap " << ScavTrap::getName() << " Gate keeper mode: ON" << std::endl;
	}
	else {
		std::cout << "ScavTrap " << ScavTrap::getName() << " Gate keeper mode: OFF" << std::endl;
	}
};
