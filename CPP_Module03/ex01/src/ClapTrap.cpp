#include "ClapTrap.hpp"
#include <iostream>
#include <istream>

#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"

void	PrintDebugInfo(std::string col, std::string msg){
	std::cout << col << msg << "\033[0m\t\t" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _ep(10), _ad(0) {
	PrintDebugInfo(GREEN, "Default constructor called!");
}

ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name), _hp(other._hp), _ep(other._ep), _ad(other._ad) {
	PrintDebugInfo(GREEN, "Copy constructor called!");
}

ClapTrap& ClapTrap::operator= (const ClapTrap& other){
	_name = other._name;
	_hp = other._hp;
	_ep = other._ep;
	_ad = other._ad;
	return (*this);
}

ClapTrap::~ClapTrap(void){
	PrintDebugInfo(RED, "Deconstructor called!");
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
	if (amount == 0) {
		std::cout << "ClapTrap " << _name << " takes no damage!" << std::endl;
		return ;
	} 
	else if (amount >= (unsigned int)_hp) {
		std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage and has been destroyed!" << std::endl;
		_hp = 0;
		return ;
	}
	else {
		std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
		_hp-=amount;
	}
}

void		ClapTrap::beRepaired(unsigned int amount) {
	if (_hp == 0) {
		std::cout << "ClapTrap " << _name << " is destroyed an cannot repair itself!" << std::endl;
	}
	else if (_hp == 10) {
		std::cout << "ClapTrap " << _name << " currently has no damage to repair!" << std::endl;
	}
	else if (_ep > 0) {
		std::cout << "ClapTrap " << _name << " repairs itself with " << amount << " points!" << std::endl;
		_ep-=amount;
	} 
	else {
		std::cout << "ClapTrap " << _name << " has no energy left!" << std::endl;
	}
}

int	ClapTrap::getAd(void) const {
	return _ad;
}

void		ClapTrap::setAd(unsigned int amount) {
	_ad = amount;
}

int	ClapTrap::getEp(void) const {
	return _ep;
}

int	ClapTrap::getHp(void) const {
	return _hp;
}

