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
