#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		~ScavTrap(void);
		void guardGate(void);
		void attack(std::string name);

	private:
		bool	_bIsGuard = false;

};
