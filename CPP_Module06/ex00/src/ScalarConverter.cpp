#include "ScalarConverter.hpp"

bool stris(const std::string str, int (*f)(int)) {
	for	(const char& c : str) {
		if (!f(c))
			return false;
	}
	return true;
}

bool isfloat(const std::string str) {
	size_t	dot;
	//Find dot and 'f'
	std::string before;
	std::string after;

	dot = str.find('.');
	// std::cout << dot << std::endl;
	if (dot != str.npos && str[(char)str.find('f')] == str[str.length() - 1]) {
		// std::cout << "Has dot and 'f' at the end" << std::endl;
		//Check if everything before dot is digit
		before = str.substr(0, dot - 1);
		//Check if everything after dot till 'f' is digit
		after = str.substr(dot + 1, str.find('f') - 3);
		std::cout << after << std::endl;
		if (stris(before, std::isdigit) && stris(after, std::isdigit))
			return true;
	}
	return false;
}

scalarType	ScalarConverter::getScalarType(const std::string scalarStr) {

	if (scalarStr.empty())
		return ERROR;
	if (isfloat(scalarStr))
		return FLOAT;
	if (stris(scalarStr, std::isalpha))
		std::cout << "it's all aplha" << std::endl;
	if (stris(scalarStr, std::isdigit))
		std::cout << "it's all digits" << std::endl;
	return ERROR;
};

int ScalarConverter::convert(const std::string scalarStr) {
	scalarType type;

	type = ScalarConverter::getScalarType(scalarStr);
	if (type == ERROR)
		return 1;
	return 0;
};

ScalarConverter::ScalarConverter() {

};

ScalarConverter::~ScalarConverter() {

};

