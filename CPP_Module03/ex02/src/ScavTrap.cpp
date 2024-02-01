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
	this->PrintDebugInfo(GREEN, "ScavTrap constructor called!");
}

ScavTrap::~ScavTrap(void) {
	this->PrintDebugInfo(RED, "~ScavTrap deconstructor called!");
}

void ScavTrap::attack(std::string name) {
	if (ClapTrap::getHp() == 0) {
		std::cout << "ScavTrap " << ScavTrap::getName() << " is destroyed and cannot do anything!" << std::endl;
	}
	else if (ClapTrap::getEp() > 0 && ClapTrap::getHp() > 0) {
		std::cout << "ScavTrap " << this->getName() << ": *TARGET ACQUIRED*, *SHOOTS LASER*," << " causing " << this->getAd() << " of damage to " << name << "!"<< std::endl;
		ClapTrap::setEp(ClapTrap::getEp() - 1);
	} 
	else {
		std::cout << "ScavTrap " << ScavTrap::getName() << " has no energy left!" << std::endl;
	}
}

void ScavTrap::guardGate(void) {
	_bIsGuard = !_bIsGuard;
	if (ClapTrap::getHp() == 0) {
		std::cout << "ScavTrap " << ScavTrap::getName() << " is destroyed and cannot do anything!" << std::endl;
	}
	else if (_bIsGuard) {
		std::cout << "ScavTrap " << ScavTrap::getName() << " Gate keeper mode: ON" << std::endl;
	}
	else {
		std::cout << "ScavTrap " << ScavTrap::getName() << " Gate keeper mode: OFF" << std::endl;
	}
};
