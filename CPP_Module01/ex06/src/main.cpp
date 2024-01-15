#include <iostream>
#include "Harl.hpp"

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

int listenToHarl(std::string input)
{
	int lvl;

	lvl = -1;
	if (input == "DEBUG")
		lvl = 0;
	if (input == "INFO")
		lvl = 1;
	if (input == "WARNING")
		lvl = 2;
	if (input == "ERROR")
		lvl = 3;
	return (lvl);
}

void	filterHarl(int lvl)
{
	Harl 		harl;

	harl = Harl();
	switch (lvl){
		case -1:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
		case 0:
			harl.complain("DEBUG");
			[[fallthrough]];
		case 1:
			harl.complain("INFO");
			[[fallthrough]];
		case 2:
			harl.complain("WARNING");
			[[fallthrough]];
		case 3:
			harl.complain("ERROR");
			break;
	}
}

int main (int argc, char *argv[])
{
	int			lvl;

	lvl = -1;
	if (argc != 2)
		return EXIT_FAILURE;

	lvl = listenToHarl(argv[1]);
	filterHarl(lvl);

	return EXIT_SUCCESS;
}
