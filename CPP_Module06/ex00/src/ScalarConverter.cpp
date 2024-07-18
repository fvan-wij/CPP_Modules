#include "ScalarConverter.hpp"
#include <string>
#include <sstream>
#include <cctype>

bool stris(const std::string& str, int (*f)(int)) {
	for	(const char& c : str) {
		if (!f(c))
			return false;
	}
	return true;
}

bool isfloat(std::string str) {
	std::string before;
	std::string after;
	size_t		dot;
	size_t		start;

	dot = str.find('.');
	if (str.find('f') == str.length() - 1)
		str.pop_back();
	start = 0;
	if (str[0] == '.' && str[1] == 'f')
		return false;
	if (str[0] == '-' || str[0] == '+') {
		start = 1;
	}
		before = str.substr(start, dot - start);
		after = str.substr(dot + 1, str.length());
		if ((stris(before, std::isdigit) && after.length() == 0) 
			|| (stris(before, std::isdigit) && stris(after, std::isdigit)))
			return true;
	return false;
}

bool isdouble(std::string str) {
	std::string before;
	std::string after;
	size_t		dot;
	size_t		start;

	dot = str.find('.');
	if (str.find('f') == str.length() - 1)
		str.pop_back();
	start = 0;
	if (str[0] == '.' && str[1] == 'f')
		return false;
	if (str[0] == '-' || str[0] == '+') {
		start = 1;
	}
		before = str.substr(start, dot - start);
		after = str.substr(dot + 1, str.length());
		if ((stris(before, std::isdigit) && after.length() == 0) 
			|| (stris(before, std::isdigit) && stris(after, std::isdigit)))
			return true;
	return false;
}

void	convertChar(const std::string &str) {
	if (str.empty()) {
		std::cout << "Impossible" << std::endl;
	} else if (stris(str, std::isdigit)) {
		char c = std::stoi(str);
		std::cout << c << std::endl;
	} else if (isfloat(str)) {
		char c = std::stof(str);
		std::cout << c << std::endl;
	} else if (isdouble(str)) {
		char c = std::stod(str);
		std::cout << c << std::endl;
	} else {
		std::cout << "Impossible" << std::endl;
	}
}

void	convertInt(const std::string &str) {
	if (str.empty()) {
		std::cout << "Impossible" << std::endl;
	} else if (stris(str, std::isdigit)) {
		std::cout << std::stoi(str) << std::endl;
	} else if (isfloat(str)) {
		int i = std::stof(str);
		std::cout << i << std::endl;
	} else if (isdouble(str)) {
		int i = std::stof(str);
		std::cout << i << std::endl;
	} else {
		std::cout << "Impossible" << std::endl;
	}
}

void	convertFloat(const std::string &str) {
	if (str.empty()) {
		std::cout << "Impossible" << std::endl;
	} else if (str == "nanf" || str == "+inff" || str == "-inff" || str == "inff") {
		std::cout << str << std::endl;
	}
	else if (isfloat(str)) {
		float f = std::stof(str);
		if (static_cast<int>(f) - f == 0) {
			std::cout << f << ".0f" << std::endl;
		}
		else {
			std::cout << f << 'f' << std::endl;
		}
	} else {
		std::cout << "Impossible" << std::endl;
	}
}

void	convertDouble(const std::string &str) {
	if (str.empty()) {
		std::cout << "Impossible" << std::endl;
	} else if (str == "nan" || str == "+inf" || str == "-inf" || str == "inf") {
		std::cout << str << std::endl;
	}  else if (isdouble(str)) {
		double d = std::stod(str);
		if (static_cast<int>(d) - d == 0) {
			std::cout << d << ".0" << std::endl;
		} else {
			std::cout << d << std::endl;
		}
	} else {
		std::cout << "Impossible" << std::endl;
	}
}

int ScalarConverter::convert(const std::string str) {
	std::cout << "Char: ";
	convertChar(str);
	std::cout << "Int: ";
	convertInt(str);
	std::cout << "Float: ";
	convertFloat(str);
	std::cout << "Double: ";
	convertDouble(str);
	return 0;
};

ScalarConverter::ScalarConverter() {

};

ScalarConverter::~ScalarConverter() {

};

