#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20) {

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
