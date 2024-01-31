#pragma once

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		~ScavTrap(void);
		void guardGate(void);
		void attack(std::string name);

	protected:
		bool	_bIsGuard = false;

};
