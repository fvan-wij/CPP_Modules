#include "ScalarConverter.hpp"

char	convertChar(const std::string &str)
{
	return str[0];
}
int		convertInt(const std::string &str, int *err)
{
	int i;

	try
	{
		i = std::stoi(str);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error " << e.what() << std::endl;
		*err = 1;
	}
	return i;
}
float	convertFloat(const std::string &str) 
{
	float f;

	try
	{
		f = std::stof(str);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error " << e.what() << std::endl;
	}
	return f;
}
double	convertDouble(const std::string &str) 
{
	double d;

	try
	{
		d = std::stod(str);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error " << e.what() << std::endl;
	}
	return d;
}


