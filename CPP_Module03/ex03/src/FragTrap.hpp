#pragma once

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
	public:
		FragTrap(void);
		FragTrap(std::string name);
		~FragTrap(void);
		void highFiveGuys(void);

	protected:

};
