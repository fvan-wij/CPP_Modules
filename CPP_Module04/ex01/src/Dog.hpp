#pragma once

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>


class Dog : public Animal {
	public:
		Dog();
		~Dog();
		void			makeSound() const;
		Brain*			getBrain() {return (_brain);};

	private:
		Brain* _brain;
};
