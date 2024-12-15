#include "RPN.hpp"
#include <iostream>

#define RPN_STRING_ARG 1

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "RPN program requires input to run (e.g. \"4 2 *\")" << std::endl;
		return -1;
	}

	try 
	{
		RPN a(argv[RPN_STRING_ARG]);
		std::cout << a.getResult() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return -1;
	}

	return 0;
}
