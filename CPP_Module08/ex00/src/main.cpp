#include <iostream>
#include <vector>
#include <array>
#include "easyfind.hpp"

void	testCorrectIndex()
{
	std::cout << "---Testing correct index---" << std::endl;
	std::vector<int> int_arr = {0, 1, 2, 3, 4, 5, 6};

	try 
	{
		auto a = easyfind(int_arr, 5);
		std::cout << "a: " << *a << std::endl;
	}
	catch (std::out_of_range& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	testOutOfBounds()
{
	std::cout << "---Testing out of bounds---" << std::endl;
	std::vector<int> int_arr = {0, 1, 2, 3, 4, 5, 6};

	try 
	{
		auto a = easyfind(int_arr, 9);
		std::cout << "a: " << *a << std::endl;
	}
	catch (std::out_of_range& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	testNegativeIndex()
{
	std::cout << "---Testing negative index---" << std::endl;
	std::vector<int> int_arr = {0, 1, 2, 3, 4, 5, 6};

	try 
	{
		auto a = easyfind(int_arr, -1);
		std::cout << "a: " << *a << std::endl;
	}
	catch (std::out_of_range& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	testDifferentContainers()
{
	std::cout << "---Testing different containers---" << std::endl;
	std::vector<int> int_vec = {0, 1, 2, 3, 4, 5, 6};
	std::array<int, 7> int_arr = {0, 1, 2, 3, 4, 5, 6};

	try 
	{
		auto a = easyfind(int_vec, 3);
		std::cout << "a: " << *a << std::endl;
		auto b = easyfind(int_arr, 3);
		std::cout << "a: " << *b << std::endl;
	}
	catch (std::out_of_range& e)
	{
		std::cout << e.what() << std::endl;
	}

}

int main(void)
{
	testCorrectIndex();
	testOutOfBounds();
	testNegativeIndex();
	testDifferentContainers();
}
