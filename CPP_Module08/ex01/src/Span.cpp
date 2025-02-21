#include "Span.hpp"
#include <algorithm>
#include <set>
#include <stdexcept>
#include <iostream>
#include <climits>

Span::Span() : _storage(nullptr), _currentIndex(0), _N(0)
{

}

Span::Span(unsigned int N) : _storage(new int[N]), _currentIndex(0), _N(N)
{
	std::cout << "Constructing Span with N: " << N << std::endl;
}

Span::Span(const Span& other)
{
	if (this == &other)
		return;

	_storage = new int[other._N];
	_currentIndex = other._currentIndex;
	_N = other._N;

	std::copy(other._storage, other._storage + other._N, _storage);
}

Span&	Span::operator=(const Span& other)
{
	if (this == &other)
		return *this;

	if (_storage != nullptr)
	{
		delete [] _storage;
	}

	_storage = new int[other._N];
	_currentIndex = other._currentIndex;
	_N = other._N;

	std::copy(other._storage, other._storage + other._N, _storage);
	return *this;
}

Span::~Span()
{
	delete [] _storage;
}

void			Span::addNumber(int number)
{
	if (_currentIndex >= _N)
	{
		throw std::out_of_range("Attempting to addNumber to an already full Span");
	}

	_storage[_currentIndex] = number;
	_currentIndex++;
}

void		Span::addNumber(int first, int last, int number)
{
	if ((first < 0 || last < 0) || (first > static_cast<int>(_N) || last > static_cast<int>(_N)))
	{
		throw std::out_of_range("Ranged addnumber is out of bounds!");
	}

	_currentIndex = last;
	std::fill(_storage + first, _storage + last, number);
}

unsigned int	Span::shortestSpan()
{
	int span = INT_MAX;
	for (size_t i = 1; i < _currentIndex; i++)
	{
		int dist = std::abs(_storage[i] - _storage[i - 1]);
		if (dist < span)
		{
			span = dist;
		}
	}
	return span;
}

unsigned int	Span::longestSpan()
{
    std::multiset<int> temp(_storage, _storage + _currentIndex);
	auto first = temp.begin();
	auto last = temp.end();
	return *(--last) - *first;
}

void	Span::printSpan()
{
	for (size_t i = 0; i < _currentIndex; i++)
	{
		std::cout << _storage[i] << std::endl;
	}
}
