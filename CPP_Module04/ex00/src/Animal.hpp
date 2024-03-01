#pragma once

#include <iostream>

#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"


class Animal {
	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		virtual ~Animal();
		virtual void			makeSound() const;
		void 					PrintDebugInfo(std::string col, std::string msg);
		std::string				getType() const;
		void					setType(std::string type);

	protected:
		std::string				_type;
};
