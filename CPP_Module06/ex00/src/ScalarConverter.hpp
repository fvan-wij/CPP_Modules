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

//		identifiers.cpp
bool	stris(const std::string& str, int (*f)(int));
bool	isdecimal(std::string str);

//		convert.cpp
char	convertChar(const std::string &str);
int		convertInt(const std::string &str, int *err);
float	convertFloat(const std::string &str);
double	convertDouble(const std::string &str);

//		print.cpp
int 	printOutput(char c, int i, float f, double d, int err);
int 	printOutput(float f, double d, int err);
void 	printSciOutput(const std::string &str);
void 	printChar(char c);
void 	printInt(int i);
void 	printFloat(float f);
void 	printDouble(double d);

class ScalarConverter {
	private:
		ScalarConverter();
		virtual ~ScalarConverter() = 0;
		static dataID	getDataType(std::string &str);

	public:
		static int 		convert(std::string str);
};
