#pragma once

#include <iostream>
#include "Brain.hpp"

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

		virtual void			makeSound() const = 0;
		void 					PrintDebugInfo(std::string col, std::string msg);
		std::string				getType() const;
		void					setType(std::string type);
		virtual Brain*			getBrain() = 0;

	private:
		std::string				_type;
};
