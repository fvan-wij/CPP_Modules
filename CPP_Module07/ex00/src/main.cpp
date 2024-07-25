#include <iostream>
#include "Templates.hpp"

void	testMax()
{
	int a = 5, b = 10;
	std::string c = "chaine1";
	std::string d = "chaine2";
	int& result = ::max(a, b);
	std::cout << "(testMax) Result: " << result << std::endl;
	std::cout << "(testMax) strings: " << ::max(c, d) << std::endl;
}

void	testMin()
{
	int a = 5, b = 10;
	std::string c = "chaine1";
	std::string d = "chaine2";
	int& result = ::min(a, b);
	std::cout << "(testMin) Result: " << result << std::endl;
	std::cout << "(testMin) strings: " << ::min(c, d) << std::endl;
}

void	testSwap()
{
	int a = 5, b = 10;
	std::cout << "(testSwap) Before: " << a << ", " << b << std::endl;
	::swap(a, b);
	std::cout << "(testSwap) After: " << a << ", " << b << std::endl;
}

// void	testDifferentArgumentType()
// {
// 	int 	a = 5;
// 	float 	b = 10;
// 	::swap(a, b);
// 	::min(a, b);
// 	::max(a, b);
// }

int main()
{
	testMax();
	testMin();
	testSwap();
	return 0;
}
