#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

int main(void)
{
	Point a(200.0, 300.0);
	Point b(300.0, 100.0);
	Point c(100.0, 100.0);

	// Point point(200.0, 150.0);
	Point point(104.0, 101.0);

	std::cout << "Is point" << point << " inside triangle a" << a << ", b" << b << ", c" << c << "?" << std::endl;
	if (bsp(a, b, c, point)){
		std::cout << "Yes" << std::endl;
	}
	else {
		std::cout << "No" << std::endl;
	}
	return (EXIT_SUCCESS);
}
