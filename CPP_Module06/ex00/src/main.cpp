#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
	if (argc == 2) {
		// std::cout << 44. << std::endl;
		return ScalarConverter::convert(argv[1]);
	}
	return (0);
}
