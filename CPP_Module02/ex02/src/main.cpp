#include <iostream>
#include <cmath>
#include "Fixed.hpp"

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

int main(void)
{
	Fixed a(4.5f);

	// std::cout << a.getRawBits() << std::endl;
	// std::cout << (448 & 255) << std::endl;

	std::cout << a.toFloat() << std::endl;
	
	return (EXIT_SUCCESS);
}
