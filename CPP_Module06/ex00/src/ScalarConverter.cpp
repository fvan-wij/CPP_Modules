#include "ScalarConverter.hpp"
#include <regex>

dataID	getDataType(std::string &str) 
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
	char	character_conversion;
	int		integer_conversion;
	float	float_conversion;
	double	double_conversion;

	switch (getDataType(str))
	{
		case CHAR:
			character_conversion = convertChar(str);
			integer_conversion = static_cast<int>(character_conversion);
			float_conversion = static_cast<float>(character_conversion);
			double_conversion = static_cast<double>(character_conversion);
			printOutput(character_conversion, integer_conversion, float_conversion, double_conversion);
			return 0;
		case INT:
			integer_conversion = convertInt(str);
			character_conversion = static_cast<char>(integer_conversion);
			float_conversion = static_cast<float>(integer_conversion);
			double_conversion = static_cast<double>(integer_conversion);
			printOutput(character_conversion, integer_conversion, float_conversion, double_conversion);
			return 0;
		case FLOAT:
			float_conversion = convertFloat(str);
			character_conversion = static_cast<char>(float_conversion);
			integer_conversion = static_cast<int>(float_conversion);
			double_conversion = static_cast<double>(float_conversion);
			printOutput(character_conversion, integer_conversion, float_conversion, double_conversion);
			return 0;
		case DOUBLE:
			double_conversion = convertDouble(str);
			character_conversion = static_cast<char>(double_conversion);
			integer_conversion = static_cast<int>(double_conversion);
			float_conversion = static_cast<float>(double_conversion);
			printOutput(character_conversion, integer_conversion, float_conversion, double_conversion);
			return 0;
		case SCI:
			double_conversion = static_cast<double>(std::stod(str));
			float_conversion = static_cast<float>(std::stof(str));
			printOutput(float_conversion, double_conversion);
			return 0;
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
