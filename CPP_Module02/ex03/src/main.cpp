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
	Point point(200.0, 150.0);

	if (bsp(a, b, c, point)){
		std::cout << "point is within triangle A-B-C" << std::endl;
	}
	else {
		std::cout << "point is not within triangle A-B-C" << std::endl;
	}
	return (EXIT_SUCCESS);
}
