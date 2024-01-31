#pragma once
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : virtual public FragTrap, virtual public ScavTrap {
	public:
		DiamondTrap(std::string name);
		~DiamondTrap(void);
		void attack(const std::string& target);
		void whoAmI(void);

	protected:
		std::string _name;
};
