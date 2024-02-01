#include "ClapTrap.hpp"
#include <iostream>
#include <istream>

ClapTrap::ClapTrap(void) : _name("DEFAULT CLAPTRAP"), _hp(10), _ep(10), _ad(0) {
	ClapTrap::PrintDebugInfo(GREEN, "ClapTrap constructor called!");
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _ep(10), _ad(0) {
	ClapTrap::PrintDebugInfo(GREEN, "ClapTrap constructor called!");
}

ClapTrap::ClapTrap(std::string name, unsigned int hp, unsigned int ep, unsigned int ad) {
	ClapTrap::PrintDebugInfo(GREEN, "ClapTrap constructor called!");
	_name 	= name;
	_hp 	= hp;
	_ep 	= ep;
	_ad 	= ad;
}

ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name), _hp(other._hp), _ep(other._ep), _ad(other._ad) {
	ClapTrap::PrintDebugInfo(GREEN, "ClapTrap copy constructor called!");
}

ClapTrap& ClapTrap::operator= (const ClapTrap& other){
	_name 	= other._name;
	_hp 	= other._hp;
	_ep 	= other._ep;
	_ad 	= other._ad;
	return (*this);
}

ClapTrap::~ClapTrap(void){
	ClapTrap::PrintDebugInfo(RED, "~ClapTrap deconstructor called!");
}

std::string	ClapTrap::getName(void) const {
	return (_name);
}

void	ClapTrap::setName(std::string name) {
	_name = name;
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
		_ep--;
	} 
	else {
		std::cout << "ClapTrap " << _name << " has no energy left!" << std::endl;
	}
}

int	ClapTrap::getHp(void) const {
	return _hp;
}

int	ClapTrap::getEp(void) const {
	return _ep;
}


int	ClapTrap::getAd(void) const {
	return _ad;
}

void		ClapTrap::setHp(unsigned int amount) {
	_hp = amount;
}

void		ClapTrap::setEp(unsigned int amount) {
	_ep = amount;
}

void		ClapTrap::setAd(unsigned int amount) {
	_ad = amount;
}

void	ClapTrap::PrintDebugInfo(std::string col, std::string msg){
	std::cout << col << msg << "\033[0m\t\t" << std::endl;
}
