#include <iostream>

typedef enum scalarType {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	ERROR
} scalarType;

bool stris(const std::string str, int (*f)(int));
bool isfloat(const std::string str);

class ScalarConverter {
	private:
		ScalarConverter();
		~ScalarConverter();
		static scalarType getScalarType(const std::string scalarStr);

	public:
		static int convert(const std::string scalarStr);
};
