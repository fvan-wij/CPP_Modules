#include <iostream>
#include "Span.hpp"

void	testOverflowingSpan()
{
	std::cout << "--Test overflowing" << std::endl;
	Span a(10);
	try
	{
		for (size_t i = 0; i < 11; i++)
		{
			a.addNumber(i);
			std::cout << "Adding number: " << i << std::endl;
		}
	}
	catch (std::out_of_range& e)
	{
		std::cout << "Error in testOverflowingSpan(): " << e.what() << "\n" << std::endl;
	}
}

void	testShortestAndLongestSpan()
{
	std::cout << "--Test shortest and longestspan" << std::endl;
	Span a(10);
	try
	{
		for (size_t i = 0; i < 10; i++)
		{
			a.addNumber(i);
			std::cout << "Adding number: " << i << std::endl;
		}
		std::cout << "\nShortest span: " << a.shortestSpan() << std::endl;
		std::cout << "Longest span: " << a.longestSpan() << "\n" << std::endl;

	}
	catch (std::out_of_range& e)
	{
		std::cout << "Error in testOverflowingSpan(): " << e.what() << "\n" << std::endl;
	}
}
void	testAddingSingleNumber()
{
	std::cout << "--Test adding single number" << std::endl;
	Span a(10);
	int n = 1;
	a.addNumber(n);
	std::cout << "Adding number: " << n <<  "\n" << std::endl;
}

void	testAddingRangeOfNumbers()
{
	std::cout << "--Test adding range of numbers" << std::endl;
	Span a(10);

	a.addNumber(0, 10, 10);
	a.printSpan();
}

void testAddingRangeOfNumbersOverflowing()
{
	std::cout << "--Test adding range of numbers overflowing" << std::endl;
	Span a(2);

	try
	{
		a.addNumber(0, 10, 10);
		a.printSpan();
	}
	catch (std::out_of_range& e)
	{
		std::cout << "Error in testAddingRangeOfNumbersOverflowing(): " << e.what() << "\n" << std::endl;
	}
}

void	testBigNumbers(unsigned int bigNumber)
{
	std::cout << "--Test bignumber" << std::endl;
	Span a(bigNumber);
	try 
	{
		a.addNumber(0, bigNumber, 2);
		std::cout << "\nShortest span: " << a.shortestSpan() << std::endl;
		std::cout << "Longest span: " << a.longestSpan() << "\n" << std::endl;
	}
	catch (std::out_of_range& e)
	{
		std::cout << "Kanker" << std::endl;
	}
}

void	testSubject()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

int main(void)
{
	testSubject();
	testOverflowingSpan();
	testShortestAndLongestSpan();
	testAddingSingleNumber();
	testAddingRangeOfNumbers();
	testAddingRangeOfNumbersOverflowing();
	testBigNumbers(10000);
}
