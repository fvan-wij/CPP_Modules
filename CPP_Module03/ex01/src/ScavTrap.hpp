#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public:
		ScavTrap(std::string name);
		~ScavTrap(void);
		void guardGate(void);
		void PrintDebugInfo(std::string col, std::string msg);
		void attack(std::string name);

	private:
		bool	_bIsGuard = false;

};
