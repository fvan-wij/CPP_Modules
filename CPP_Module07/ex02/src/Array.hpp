#pragma once
#include <iostream>

template <typename T>
class Array 
{
	private:
		unsigned int	m_Size;
		T 				*arr;

	public:
		Array();
		Array(unsigned int n);
		Array(Array& other);
		Array& operator=(const Array& obj);
		int size() const;
		~Array();
};

//Template code

template <typename T>
Array<T>::Array() : m_Size(0), arr(nullptr)
{
	std::cout << "Created Array template" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : m_Size(n)
{
	arr = new T[n];

	std::fill(arr, arr + n, T());

	std::cout << "Created Array template of size " << n << std::endl;
}

template <typename T>
Array<T>::Array(Array& other) : m_Size(other.m_Size), arr(new T[other.size()]) 
{
	for (size_t i = 0; i < m_Size; i++)
		arr[i] = other.arr[i];
	std::cout << "Copy constructor called" << std::endl;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& obj)
{
	if (this == &obj)
	{
		std::cout << "Copy assignment operator called" << std::endl;
		return *this;
	}
	else if (arr)
		delete [] arr;

	arr = new T[obj.size()];
	m_Size = obj.size();
	for (size_t i = 0; i < m_Size; i++)
		arr[i] = obj.arr[i];
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	delete [] arr;
	std::cout << "~Destroyed Array template" << std::endl;
}

template <typename T>
int Array<T>::size() const
{
	return m_Size;
}
