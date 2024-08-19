#pragma once
#include <iostream>

template <typename T>
class Array 
{
	private:
		unsigned int	_size;
		T 				*_arr;

	public:
		Array();
		Array(unsigned int n);
		Array(Array& other);
		Array& operator=(const Array& obj);
		T &operator[](unsigned int index);

		unsigned int size() const;
		~Array();
};

//Template code

template <typename T>
Array<T>::Array() : _size(0), _arr(nullptr)
{
	std::cout << "Created Array template" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
	_arr = new T[n];

	std::fill(_arr, _arr + n, T());

	std::cout << "Created Array template of size " << n << std::endl;
}

template <typename T>
Array<T>::Array(Array& other) : _size(other._size), _arr(new T[other.size()]) 
{
	for (size_t i = 0; i < _size; i++)
		_arr[i] = other._arr[i];
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
	else if (_arr)
		delete [] _arr;

	_arr = new T[obj.size()];
	_size = obj.size();
	for (size_t i = 0; i < _size; i++)
		_arr[i] = obj._arr[i];
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index < _size)
		return _arr[index];
	throw std::out_of_range("Index out of bounds");
}

template <typename T>
std::ostream& operator<<(std::ostream& os, Array<T> &obj)
{
	for (size_t i = 0; i < obj.size(); i++)
	{
		os << "[" << obj[i] << "] ";
	}
	return (os);
}

template <typename T>
Array<T>::~Array()
{
	delete [] _arr;
	std::cout << "~Destroyed Array template" << std::endl;
}

template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}
