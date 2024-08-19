#include <iostream>
#include "Array.hpp"
#include <array>
#include <stdlib.h>

void	testArrayConstructionNoParam()
{
	std::cout << "\n--Test: Construction with no parameter--" << std::endl;
	Array<int> arr{};
	std::cout << "Size of array: " << arr.size() << std::endl;
}

void	testUnsignedIntAsParam(unsigned int n)
{
	std::cout << "\n--Test: Unsigned int " << n << " as parameter--" << std::endl;
	Array<int> arr(n);
	std::cout << "Size of array: " << arr.size() << std::endl;
}

// void	testArrayConstructionCopy()
// {
// 	std::cout << "\n--Test: Unsigned int " << n << " as parameter--" << std::endl;
// 	Array<int> arr();
// 	std::cout << "Size of array: " << arr.size() << std::endl;
// }

int main()
{
	// testArrayConstructionNoParam();
	// testUnsignedIntAsParam(10);
	Array<int> arr(4);
	arr[0] = 1;
	arr[1] = 2;
	std::cout << arr[0] << ", " << arr[1] << std::endl;
	std::cout << arr << std::endl;

	return 0;
}
