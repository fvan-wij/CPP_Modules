#include "ScalarConverter.hpp"

bool stris(const std::string& str, int (*f)(int)) 
{
	for	(const char& c : str) {
		if (!f(c))
		{
			return false;
		}
	}
	return true;
}

bool isdecimal(std::string str) 
{
	std::string before;
	std::string after;
	size_t		dot;

	dot = str.find('.');
	if (str.find('f') == str.length() - 1)
		str.pop_back();
	if (str[0] == '.' && str[1] == 'f')
		return false;
	before = str.substr(0, dot);
	after = str.substr(dot + 1, str.length());
	if ((stris(before, std::isdigit) && after.length() == 0) 
			|| (stris(before, std::isdigit) && stris(after, std::isdigit)))
		return true;
	return false;
}

char	convertChar(const std::string &str)
{
	return str[0];
}
int		convertInt(const std::string &str)
{
	int i;

	try
	{
		i = std::stoi(str);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error " << e.what() << std::endl;
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


void printChar(char c)
{
	if (!std::isprint(c))
		std::cout << "Char: Non-printable" << std::endl;
	// else if (type == SCI_D || type == SCI_F)
	// 	std::cout << "Char: Impossible" << std::endl;
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
	std::cout << "Double: " << d << std::endl;
}

void printSciOutput(const std::string &str)
{
	std::cout << "Char: impossible" << std::endl;
	std::cout << "Int: impossible" << std::endl;
	std::cout << "Float: " << str << 'f' << std::endl;
	std::cout << "Double: " << str << std::endl;
}

void printOutput(char c, int i, float f, double d)
{
	printChar(c);
	printInt(i);
	printFloat(f);
	printDouble(d);
}

void printOutput(float f, double d)
{
	std::cout << "Char: impossible" << std::endl;
	std::cout << "Int: impossible" << std::endl;
	printFloat(f);
	printDouble(d);
}

