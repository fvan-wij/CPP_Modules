#pragma once
#include <string>
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"


class Animal {
	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		~Animal();
		void			makeSound();
		void 			PrintDebugInfo(std::string col, std::string msg);
		std::string		getType() {return _type;};
		void			setType(std::string type) {_type = type;};

	protected:
		std::string		_type;
};
