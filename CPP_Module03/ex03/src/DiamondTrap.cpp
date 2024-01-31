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
	std::cout << "*EXISTENTIAL NOISE* I am... " << _name << "! Which is derived from " << ClapTrap::getName() << std::endl;
}
