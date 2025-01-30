#include "PmergeMe.hpp"
#include <cstddef>
#include <iostream>

PmergeMe::PmergeMe()
{

}

std::vector<int>	PmergeMe::sort(std::vector<int>&	elements)
{
	std::vector<std::pair<int, int>>	pairs;
	int									unpaired = -1;

	for (size_t i = 1; i < elements.size(); i+=2)
	{
		pairs.push_back({elements[i - 1], elements[i]});
	}
	if (elements.size() % 2 != 0)
		unpaired = elements.back();

	std::vector<int>	largerElements;
	for (auto& [a, b] : pairs)
	{
		std::cout << "pair[" << a << ", " << b << "]\n";
		largerElements.push_back(std::max(a, b));
	}
	if (unpaired >= 0)
	{
		std::cout << "unpaired[" << unpaired << "]\n";
		largerElements.push_back(unpaired);
	}
	std::cout << std::endl;

	return elements;
}

PmergeMe::~PmergeMe()
{

}
