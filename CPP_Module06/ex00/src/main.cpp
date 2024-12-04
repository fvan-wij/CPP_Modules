#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
	if (argc == 2) {
		ScalarConverter::convert(argv[1]);
		return 0;
	}
	else {
		std::cerr << "Provide strictly 1 argument to be converted. I.e: './app 42.0f'" << std::endl;
		return 1;
	}
}