#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"


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

	ScavTrap scavneck = ScavTrap("Scavneck");
	scavneck.attack("Scrapneck");
	scrapneck.takeDamage(scavneck.getAd());
	std::cout << "Scrapneck's HP: " << scrapneck.getHp() << std::endl;
	std::cout << "Scavneck's EP: " << scavneck.getEp() << std::endl;

	scavneck.guardGate();
	scavneck.guardGate();

	FragTrap fragneck = FragTrap("Fragneck");
	fragneck.highFiveGuys();
	fragneck.attack("Scavneck");

	DiamondTrap diamondneck = DiamondTrap("Diamondneck");
	diamondneck.whoAmI();
	std::cout << "Diamondnecks's HP: " << diamondneck.getHp() << std::endl;
	std::cout << "Diamondnecks's EP: " << diamondneck.getEp() << std::endl;
	diamondneck.attack("Fragneck");

	fragneck.takeDamage(diamondneck.getAd());

	std::cout << "Diamondnecks's HP: " << diamondneck.getHp() << std::endl;
	std::cout << "Fragneck's HP: " << fragneck.getHp() << std::endl;
	return (EXIT_SUCCESS);
}
