#include <iostream>

typedef enum dataID
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	SCI,
	INVALID
} dataID;

bool	stris(const std::string& str, int (*f)(int));
bool	isdecimal(std::string str);
char	convertChar(const std::string &str);
int		convertInt(const std::string &str);
float	convertFloat(const std::string &str);
double	convertDouble(const std::string &str);
void 	printOutput(char c, int i, float f, double d);
void 	printOutput(float f, double d);
void 	printSciOutput(const std::string &str);
dataID	getDataType(std::string &str);

void printChar(char c);
void printInt(int i);
void printFloat(float f);
void printDouble(double d);

class ScalarConverter {
	private:
		ScalarConverter();
		~ScalarConverter();

	public:
		static int convert(std::string str);
};
