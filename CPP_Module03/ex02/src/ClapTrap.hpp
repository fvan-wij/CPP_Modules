#pragma once
#include <string>
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"


class ClapTrap{
	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(std::string name, unsigned int hp, unsigned int ep, unsigned int ad);
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& other);
		~ClapTrap(void);

		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

		int			getHp(void) const;
		int			getEp(void) const;
		int			getAd(void) const;

		void		setHp(unsigned int amount);
		void		setEp(unsigned int amount);
		void		setAd(unsigned int amount);

		void		setName(std::string name);
		std::string	getName(void) const;

		void 		PrintDebugInfo(std::string col, std::string msg);
	private:
		std::string _name;
		int			_hp;
		int			_ep;
		int			_ad;
};

