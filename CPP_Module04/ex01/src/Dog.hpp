#pragma once

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>


class Dog : public Animal {
	public:
		Dog();
		~Dog();
		void			makeSound() const;

	private:
		Brain* _brain;
};
