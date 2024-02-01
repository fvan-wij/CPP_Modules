#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(std::string name) {
	DiamondTrap::PrintDebugInfo(GREEN, "DiamondTrap consructor called!");
	_name = name;
	ClapTrap::setName(name + "_clap_name");
	DiamondTrap::setHp(FragTrap::_hp);
	DiamondTrap::setEp(ScavTrap::_ep);
	DiamondTrap::setAd(FragTrap::_ad);
}

DiamondTrap::~DiamondTrap(void) {
	DiamondTrap::PrintDebugInfo(RED, "~DiamondTrap deconsructor called!");
}

void DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void) {
	if (DiamondTrap::getHp() > 0) {
		std::cout << "*EXISTENTIAL NOISE* I am... " << _name << "! But my base model is " << ClapTrap::getName() << std::endl;
	} else {
		std::cout << DiamondTrap::getName() << " is dead and cannot do anything!" << std::endl;
	}
}
