#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
	public:
		Cat();
		~Cat();

		void			makeSound() const;
		Brain*			getBrain() {return (_brain);};

	private:
		Brain* _brain;
};
