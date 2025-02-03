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

void	PmergeMe::merge(std::vector<int>& elements, size_t low, size_t mid, size_t high)
{
	std::vector<int>	subarrayL(elements.begin() + low, elements.begin() + mid + 1);
	std::vector<int>	subarrayR(elements.begin() + mid + 1, elements.begin() + high + 1);

	std::cout << "low: " << low << ", mid: " << mid << ", high: " << high << std::endl;

	size_t iL = 0;
	size_t iR = 0;
	size_t	i = low;

	while (iL < subarrayL.size() && iR < subarrayR.size())
	{
		if (subarrayL[iL] <= subarrayR[iR])
		{
			elements[i] = subarrayL[iL];
			iL++;
		}
		else
		{
			elements[i] = subarrayR[iR];
			iR++;
		}
		i++;
	}
	while (iL < subarrayL.size())
	{
		elements[i] = subarrayL[iL];
		iL++;
		i++;
	}
	while (iR < subarrayR.size())
	{
		elements[i] = subarrayR[iR];
		iR++;
		i++;
	}
}

void	PmergeMe::mergeSort(std::vector<int>&	elements, size_t low, size_t high)
{
	if (low >= high)
		return;

	size_t	mid = (low + high) / 2;

	mergeSort(elements, low, mid);
	mergeSort(elements, mid + 1, high);
	merge(elements, low, mid, high);
}

PmergeMe::~PmergeMe()
{

}
