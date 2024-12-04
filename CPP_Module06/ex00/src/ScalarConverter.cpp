#include "ScalarConverter.hpp"
#include <regex>

dataId	ScalarConverter::getDataId(std::string &str) 
{
	int start = 0;

	if (str[0] == '+' || str[0] == '-')
		start = 1;
	if (str.length() == 1 && std::isalpha(str[0]) && std::isprint(str[0]))
		return dataId::Char;
	else if (str == "nanf" || str == "+inff" || str == "-inff" || str == "inff" 
			|| str == "nan" || str == "+inf" || str == "-inf" || str == "inf")
		return dataId::Sci;
	else if (stris(str.substr(start, str.length()), std::isdigit))
		return dataId::Int;
	else if (std::regex_match(str, std::regex("[-+]?[0-9]+.[0-9]+f")))
	{
		if (str.find('f') == str.length() - 1)
			str.pop_back();
		return dataId::Float;
	}
	else if (std::regex_match(str, std::regex("[-+]?[0-9]+.[0-9]+")))
		return dataId::Double;
	return dataId::Invalid;
}

int ScalarConverter::convert(std::string str) 
{
	char	c;
	int		i;
	float	f;
	double	d;
	int		err;

	err = 0;
	switch (getDataId(str))
	{
		case dataId::Char:
			c = convertChar(str);
			i = static_cast<int>(c);
			f = static_cast<float>(c);
			d = static_cast<double>(c);
			return printOutput(c, i, f, d, err);
		case dataId::Int:
			i = convertInt(str, &err);
			c = static_cast<char>(i);
			f = static_cast<float>(i);
			d = static_cast<double>(i);
			return printOutput(c, i, f, d, err);
		case dataId::Float:
			f = convertFloat(str);
			c = static_cast<char>(f);
			i = static_cast<int>(f);
			d = static_cast<double>(f);
			return printOutput(c, i, f, d, err);
		case dataId::Double:
			d = convertDouble(str);
			c = static_cast<char>(d);
			i = static_cast<int>(d);
			f = static_cast<float>(d);
			return printOutput(c, i, f, d, err);
		case dataId::Sci:
			f = static_cast<float>(std::stof(str));
			d = static_cast<double>(std::stod(str));
			return printOutput(f, d, err);
		case dataId::Invalid:
			std::cout << "Invalid input! Make sure your input is a convertible string" << std::endl;
			return 1;
	}
	return 0;
};

ScalarConverter::ScalarConverter() {

};

ScalarConverter::~ScalarConverter() {

};
