#include <iostream>
#include "ClapTrap.hpp"


#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

int main(void)
{
	ClapTrap dude = ClapTrap("The Dude");

	ClapTrap other = ClapTrap("The Other");

	dude.attack("The Other");
	other.takeDamage(0);

	return (EXIT_SUCCESS);
}
