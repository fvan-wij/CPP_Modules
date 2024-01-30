#pragma once
#include <string>

class ClapTrap{
	public:
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& other);
		~ClapTrap();

		std::string	getName() const;
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
