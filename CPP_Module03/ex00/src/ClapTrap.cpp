#include "ClapTrap.hpp"
#include <iostream>
#include <istream>

ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _ep(10), _ad(0) {

}

ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name), _hp(other._hp), _ep(other._ep), _ad(other._ad) {

}

ClapTrap& ClapTrap::operator= (const ClapTrap& other){
	_name = other._name;
	_hp = other._hp;
	_ep = other._ep;
	_ad = other._ad;
	return (*this);
}

ClapTrap::~ClapTrap(){
}

std::string	ClapTrap::getName() const {
	return (_name);
}

void		ClapTrap::attack(const std::string& target) {
	if (_ep > 0) {
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _ad << " points of damage!" << std::endl;
		_ep--;
	} 
	else {
		std::cout << "ClapTrap " << _name << " has no energy left!" << std::endl;
	}
}

void		ClapTrap::takeDamage(unsigned int amount) {

	std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
	_hp-=amount;
}

void		ClapTrap::beRepaired(unsigned int amount) {
	if (_ep > 0) {
		std::cout << "ClapTrap " << _name << " repairs itself with " << amount << " points!" << std::endl;
		_ep-=amount;
	} 
	else {
		std::cout << "ClapTrap " << _name << " has no energy left!" << std::endl;
	}
}

