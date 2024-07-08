#include "ScalarConverter.hpp"

bool stris(const std::string str, int (*f)(int)) {
	for	(const char& c : str) {
		if (!f(c))
			return false;
	}
	return true;
}

bool isfloat(const std::string str) {
	std::string before;
	std::string after;
	size_t		dot;

	dot = str.find('.');
	if (dot != str.npos && str[(char)str.find('f')] == str[str.length() - 1]) {
		before = str.substr(0, dot);
		after = str.substr(dot + 1, str.rfind('f'));
		after.pop_back();
		if (stris(before, std::isdigit) && stris(after, std::isdigit)) {
			return true;
		}
	}
	return false;
}

scalarType	ScalarConverter::getScalarType(const std::string scalarStr) {

	if (scalarStr.empty())
		return ERROR;
	if (isfloat(scalarStr)) {
		std::cout << "It's a float: " << scalarStr << std::endl;
		return FLOAT;
	}
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

