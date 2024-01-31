#include <cstdio>
#include <iostream>
#include <cmath>
#include "Fixed.hpp"

int main(void)
{
	//Testing comparision operators "< and >"
	Fixed a(42.3f);
	Fixed b(42.2f);
	if (a > b){
		std::cout << "a is bigger than b" << std::endl;
	}
	else {
		std::cout << "b is bigger than a" << std::endl;
	}

	if (a < b){
		std::cout << "a is smaller than b" << std::endl;
	}
	else {
		std::cout << "b is smaller than a" << std::endl;
	}

	//Testing comparision operators "<= and >="
	Fixed d(12.88f);
	Fixed e(12.89f);
	if (d <= e){
		std::cout << "d is smaller than or equal to e" << std::endl;
	}
	else {
		std::cout << "e is smaller than d" << std::endl;
	}

	if (d >= e){
		std::cout << "d is bigger than or equal to e" << std::endl;
	}
	else {
		std::cout << "e is bigger than d" << std::endl;
	}

	//Testing comparision operators "!= and =="
	if (d == e){
		std::cout << "d is equal to e" << std::endl;
	}
	else {
		std::cout << "d is not equal to d" << std::endl;
	}

	if (d != e){
		std::cout << "d is not equal to e" << std::endl;
	}
	else {
		std::cout << "d is equal to e" << std::endl;
	}

	//Testing arithmetic operator "++"
	Fixed plus;

	std::cout << plus << std::endl;
	std::cout << ++plus << std::endl;
	std::cout << plus << std::endl;
	std::cout << plus++ << std::endl;
	std::cout << plus << std::endl;


	// //Testing arithmetic operator "+"
	Fixed add(Fixed(5.05f) + Fixed(2));
	std::cout << "add: " << add << std::endl;

	// //Testing arithmetic operator "-"
	Fixed subtract(Fixed(5.05f) - Fixed(2));
	std::cout << "subtract: " << subtract << std::endl;

	//Testing arithmetic operator "*"
	Fixed mult(Fixed(5.05f) * Fixed(2));
	std::cout << "mult: " << mult << std::endl;

	// //Testing arithmetic operator "/"
	Fixed divide(Fixed(10.05f) / Fixed(2));
	std::cout << "divide: " << divide << std::endl;

	// //Testing Min
	std::cout << "Fixed::min(mult, divide): " << Fixed::min(mult, divide) << std::endl;

	// //Testing Min
	std::cout << "Fixed::max(add, subtract): " << Fixed::max(add, subtract) << std::endl;

	return (0);
}
