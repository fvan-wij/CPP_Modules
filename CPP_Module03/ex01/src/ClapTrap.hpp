#pragma once
#include <string>

class ClapTrap{
	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(std::string name, unsigned int hp, unsigned int ep, unsigned int ad);
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& other);
		~ClapTrap(void);

		std::string	getName(void) const;
		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		int			getAd(void) const;
		int			getEp(void) const;
		int			getHp(void) const;
		void		setAd(unsigned int amount);

	private:
		std::string _name;
		int			_hp;
		int			_ep;
		int			_ad;
};
