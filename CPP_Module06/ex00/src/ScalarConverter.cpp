#include "ScalarConverter.hpp"
#include <regex>

dataID	ScalarConverter::getDataType(std::string &str) 
{
	int start = 0;

	if (str[0] == '+' || str[0] == '-')
		start = 1;
	if (str.length() == 1 && std::isdigit(str[0]) && std::isprint(str[0]))
		return CHAR;
	else if (str == "nanf" || str == "+inff" || str == "-inff" || str == "inff" 
			|| str == "nan" || str == "+inf" || str == "-inf" || str == "inf")
		return SCI;
	else if (stris(str.substr(start, str.length()), std::isdigit) )
		return INT;
	else if (std::regex_match(str, std::regex("[-+]?[0-9]+.[0-9]+f")))
	{
		if (str.find('f') == str.length() - 1)
			str.pop_back();
		return FLOAT;
	}
	else if (std::regex_match(str, std::regex("[-+]?[0-9]+.[0-9]+")))
		return DOUBLE;
	return INVALID;
}

int ScalarConverter::convert(std::string str) 
{
	char	c;
	int		i;
	float	f;
	double	d;
	int		err;

	switch (getDataType(str))
	{
		case CHAR:
			c = convertChar(str);
			i = static_cast<int>(c);
			f = static_cast<float>(c);
			d = static_cast<double>(c);
			return printOutput(c, i, f, d, err);
		case INT:
			i = convertInt(str, &err);
			c = static_cast<char>(i);
			f = static_cast<float>(i);
			d = static_cast<double>(i);
			return printOutput(c, i, f, d, err);
		case FLOAT:
			f = convertFloat(str);
			c = static_cast<char>(f);
			i = static_cast<int>(f);
			d = static_cast<double>(f);
			return printOutput(c, i, f, d, err);
		case DOUBLE:
			d = convertDouble(str);
			c = static_cast<char>(d);
			i = static_cast<int>(d);
			f = static_cast<float>(d);
			return printOutput(c, i, f, d, err);
		case SCI:
			f = static_cast<float>(std::stof(str));
			d = static_cast<double>(std::stod(str));
			return printOutput(f, d, err);
		case INVALID:
			std::cout << "Invalid input! Make sure your input is a convertible string" << std::endl;
			return 1;
	}
	return 0;
};

ScalarConverter::ScalarConverter() {

};

ScalarConverter::~ScalarConverter() {

};
