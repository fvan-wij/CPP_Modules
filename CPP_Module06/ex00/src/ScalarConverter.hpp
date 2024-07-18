#include <iostream>

bool	stris(const std::string& str, int (*f)(int));
bool	isfloat(std::string str);
bool 	isdouble(std::string str);
void	convertChar(const std::string &str);
void	convertInt(const std::string &str);
void	convertFloat(const std::string &str);
void	convertDouble(const std::string &str);

class ScalarConverter {
	private:
		ScalarConverter();
		~ScalarConverter();

	public:
		static int convert(const std::string str);
};
