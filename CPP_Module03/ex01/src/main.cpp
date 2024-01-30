#include <iostream>
#include "ClapTrap.hpp"


#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

int main(void)
{
	ClapTrap scrapneck = ClapTrap("Scrapneck");
	ClapTrap duderadiator = ClapTrap("Duderadiator");

	scrapneck.setAd(12);
	scrapneck.attack("Duderadiator");

	duderadiator.takeDamage(scrapneck.getAd());

	std::cout << "Scrapneck's EP: " << scrapneck.getEp() << std::endl;
	std::cout << "Duderadiator's EP: " << duderadiator.getEp() << std::endl;

	std::cout << "Scrapneck's HP: " << scrapneck.getHp() << std::endl;
	std::cout << "Duderadiator's HP: " << duderadiator.getHp() << std::endl;

	duderadiator.beRepaired(2);
	scrapneck.beRepaired(2);

	return (EXIT_SUCCESS);
}
