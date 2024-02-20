#pragma once

#include <iostream>

#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"

class WrongAnimal {
	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal& operator=(const WrongAnimal& other);
		~WrongAnimal();

		void 					PrintDebugInfo(std::string col, std::string msg);
		void					makeSound() const;
		std::string				getType() const {return _type;} ;
		void					setType(std::string type) {_type = type;} ;

	protected:
		std::string				_type;
};
