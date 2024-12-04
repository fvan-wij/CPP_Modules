#include "Array.hpp"
#include <iostream>

template <typename T>
Array<T>::Array() : arr_size(0), T(nullptr)
{
	std::cout << "Created Array template" << std::endl;
}

template <typename T>
Array<T>::~Array()
{
	delete[] arr;
	std::cout << "~Destroyed Array template" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : arr_size(n)
{
	arr = new T[n];

	for (auto &i : arr)
	{
		arr[i] = T();
		std::cout << arr[i] << std::endl;
	}

	std::cout << "Created Array template of size " << n << std::endl;
}
