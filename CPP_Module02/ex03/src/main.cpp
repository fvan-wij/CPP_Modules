#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

int main(void)
{
	Point a(100.0, 100.0);
	Point b(200.0, 0.0);
	Point c(0.0, 0.0);

	// Point point(200.0, 150.0);
	Point point(50.0, 1.0);

	std::cout << "Is point" << point << " inside triangle {a" << a << ", b" << b << ", c" << c << "}?" << std::endl;

	if (bsp(a, b, c, point)){
		std::cout << "Yes" << std::endl;
	}
	else {
		std::cout << "No" << std::endl;
	}
	return (EXIT_SUCCESS);
}
