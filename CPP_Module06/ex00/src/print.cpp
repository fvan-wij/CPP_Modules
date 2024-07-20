#include "ScalarConverter.hpp"

void printChar(char c)
{
	if (!std::isprint(c))
		std::cout << "Char: Non-printable" << std::endl;
	else 
		std::cout << "Char: '" << c << "'" << std::endl;
}

void printInt(int i)
{
	std::cout << "Int: " << i << std::endl;

}

void printFloat(float f)
{
	std::cout << "Float: " << f;
	if ((static_cast<int>(f) - f) == 0)
		std::cout << ".0f" << std::endl;
	else
		std::cout << "f" << std::endl;

}

void printDouble(double d)
{
	std::cout << "Double: " << d;
	if ((static_cast<int>(d) - d) == 0)
		std::cout << ".0";
	std::cout << std::endl;
}

void printSciOutput(const std::string &str)
{
	std::cout << "Char: impossible" << std::endl;
	std::cout << "Int: impossible" << std::endl;
	std::cout << "Float: " << str << 'f' << std::endl;
	std::cout << "Double: " << str << std::endl;
}

int printOutput(char c, int i, float f, double d, int err)
{
	if (err == 1)
		return 1;
	printChar(c);
	printInt(i);
	printFloat(f);
	printDouble(d);
	return 0;
}

int printOutput(float f, double d, int err)
{
	if (err)
		return 1;
	std::cout << "Char: impossible" << std::endl;
	std::cout << "Int: impossible" << std::endl;
	printFloat(f);
	printDouble(d);
	return 0;
}

