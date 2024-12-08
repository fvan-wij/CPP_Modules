#include "Span.hpp"
#include <algorithm>

Span::Span() : _storage(nullptr), _currentIndex(0), _N(0)
{

}

Span::Span(unsigned int N) : _storage(new int[N]), _currentIndex(0), _N(N)
{

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
	return 0;
}

unsigned int	Span::longestSpan()
{
	return 0;
}

void	Span::printSpan()
{
	for (size_t i = 0; i < _currentIndex; i++)
	{
		std::cout << _storage[i] << std::endl;
	}
}


