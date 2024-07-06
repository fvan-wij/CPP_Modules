#include "ScalarConverter.hpp"

static bool stris(const std::string str, int (*f)(int)) {
	for	(const char& c : str) {
		if (!f(c))
			return false;
	}
	return true;
}

static bool isfloat(const std::string str) {
	return true;
}

ScalarConverter::ScalarConverter() {

};

ScalarConverter::~ScalarConverter() {

};

scalarType	ScalarConverter::getScalarType(const std::string scalarStr) {

	if (scalarStr.empty())
		return ERROR;
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
