#include "Base.hpp"
#include "DerivedA.hpp"
#include "DerivedB.hpp"
#include "DerivedC.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base::Base() {

}

Base::~Base() {

}

Base*	generate() {
	srand(static_cast<unsigned>(time(0)));
	const float c = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
	if (c < 0.33) {
		std::cout << "Generating DerivedA" << std::endl;
		return new DerivedA();
	} else if (c >= 0.33 && c < 0.66) {
		std::cout << "Generating DerivedB" << std::endl;
		return new DerivedB();
	} else {
		std::cout << "Generating DerivedC" << std::endl;
		return new DerivedC();
	}
}

void	identify(Base* p) {
		std::cout << "Identifying pointer... ";

		if (dynamic_cast<DerivedA*>(p))
			std::cout << "A!" << std::endl;
		else if (dynamic_cast<DerivedB*>(p))
			std::cout << "B!" << std::endl;
		else if (dynamic_cast<DerivedC*>(p))
			std::cout << "C!" << std::endl;
}

void	identify(Base& r) {
	std::cout << "Identifying reference... ";

	if (dynamic_cast<DerivedA*>(&r))
		std::cerr << "A!" << std::endl;
	else if (dynamic_cast<DerivedB*>(&r))
		std::cerr << "B!" << std::endl;
	else if (dynamic_cast<DerivedC*>(&r))
		std::cerr << "C!" << std::endl;
}
