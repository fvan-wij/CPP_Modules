#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public:
		ScavTrap(std::string name);
		void guardGate(void);

	private:
		bool	_bIsGuard = false;

};
