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
	std::cout << "\n--Test Default Consructor: Unsigned int " << n << " as parameter--" << std::endl;
	Array<int> arr(n);
	std::cout << "Size of array: " << arr.size() << std::endl;
}

void	testArrayConstructionCopy(unsigned int n)
{
	std::cout << "\n--Test Copy Constructor: Unsigned int " << n << " as parameter, copying arr to yarr--" << std::endl;
	Array<int> arr(n);
	Array<int> yarr(arr);
	std::cout << "Size of array: " << arr.size() << std::endl;
	std::cout << "Size of yarray: " << yarr.size() << std::endl;
}

void testOutOfBoundsAccess()
{
	std::cout << "\n--Test Out Of Bounds: accessing index 6 while size is 5--" << std::endl;
	try 
	{
		Array<int> arr(5);
		std::cout << "array at index 6" << std::endl;
		int a = arr[5];
		std::cout << "a is : " << a << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}

int main()
{
	testArrayConstructionNoParam();
	testUnsignedIntAsParam(10);
	testArrayConstructionCopy(10);
	testOutOfBoundsAccess();

	// Array<int> arr(4);
	// arr[0] = 1;
	// arr[1] = 2;
	// std::cout << arr[0] << ", " << arr[1] << std::endl;
	// std::cout << arr << std::endl;

	return 0;
}
