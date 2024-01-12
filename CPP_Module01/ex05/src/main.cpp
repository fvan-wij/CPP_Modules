#include <iostream>
#include "Harl.hpp"

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

int main ()
{
	Harl harl = Harl();

	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");

	return EXIT_SUCCESS;
}
