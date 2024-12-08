#pragma once

#include <set>

class Span
{
	public:
		Span();
		Span(unsigned int N);
		Span(const Span& other);
		Span&	operator=(const Span& other);
		~Span();

		void			addNumber(int number);
		void			addNumber(int first, int last, int number);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();
		void			printSpan();

	private:
		int				*_storage;
		// std::set<int>	_storage;
		unsigned int	_currentIndex;
		unsigned int 	_N;
};


