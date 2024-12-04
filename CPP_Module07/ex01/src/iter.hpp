#pragma once
#include <cstdlib>
#include <iostream>

template <typename T, typename F>
void	iter(T& array, size_t len, F func)
{
	for (size_t i = 0; i < len; i++)
		func(array[i]);
}

template <typename T>
void	print(T& x)
{
	std::cout << x << std::endl;
}

template <typename T>
bool	is_digit(T& element)
{
	if (std::isdigit(element))
	{
		std::cout << element << " is digit" << std::endl;
		return true;
	}
	else
	{
		std::cout << element << " is not a digit" << std::endl;
	}
	return false;
}