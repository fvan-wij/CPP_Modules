#include "PmergeMe.hpp"
#include <cstddef>
#include <iostream>
#include <algorithm>

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

void	PmergeMe::merge(std::vector<std::pair<int, int>>& pairs, size_t low, size_t mid, size_t high)
{
	std::vector<std::pair<int, int>>	subarrayL(pairs.begin() + low, pairs.begin() + mid + 1);
	std::vector<std::pair<int, int>>	subarrayR(pairs.begin() + mid + 1, pairs.begin() + high + 1);

	std::cout << "low: " << low << ", mid: " << mid << ", high: " << high << std::endl;

	size_t iL = 0;
	size_t iR = 0;
	size_t	i = low;

	while (iL < subarrayL.size() && iR < subarrayR.size())
	{
		if (subarrayL[iL].first <= subarrayR[iR].first)
		{
			pairs[i] = subarrayL[iL];
			iL++;
		}
		else
		{
			pairs[i] = subarrayR[iR];
			iR++;
		}
		i++;
	}
	while (iL < subarrayL.size())
	{
		pairs[i] = subarrayL[iL];
		iL++;
		i++;
	}
	while (iR < subarrayR.size())
	{
		pairs[i] = subarrayR[iR];
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

void	PmergeMe::mergeSort(std::vector<std::pair<int, int>>& pairs, size_t low, size_t high)
{
	if (low >= high)
		return;

	size_t	mid = (low + high) / 2;

	mergeSort(pairs, low, mid);
	mergeSort(pairs, mid + 1, high);
	merge(pairs, low, mid, high);
}

void PmergeMe::mergeInsertionSort(std::vector<int>& elements)
{
	int oddOne = -1;

	// Group into n/2 pairs
	if (elements.size() % 2 == 1)
	{
		oddOne = elements.back();
		elements.pop_back();
	}
	size_t nPairs = elements.size() / 2;
	std::vector<std::pair<int, int>> pairs;
	pairs.reserve(nPairs);

	// Swap elements in pair so that the most significant number is first
	for (size_t i = 0; i < nPairs; i++)
	{
		std::pair p{elements[i * 2], elements[i * 2 + 1]};
		if (p.first < p.second)
			std::swap(p.first, p.second);
		pairs.push_back(p);
	}

	// Recursively sort pairs based on the first number
	for (const auto& [a, b] : pairs)
	{
		std::cout << "[" << a << ", " << b << "]" << std::endl;
	}
	std::cout << "mergeSort..." << std::endl;
	mergeSort(pairs, 0, pairs.size() - 1);
	for (const auto& [a, b] : pairs)
	{
		std::cout << "[" << a << ", " << b << "]" << std::endl;
	}
	if (oddOne != -1)
		std::cout << "oddOne: " << oddOne << std::endl;


	// Create main and pend chain
	std::vector<int> main, pend;
	main.reserve(pairs.size());
	pend.reserve(pairs.size());
	for (const auto& [a, b] : pairs)
	{
		main.push_back(a);
		pend.push_back(b);
	}
	std::cout << "main: [";
	for (size_t i = 0; i < main.size(); i++)
	{
		std::cout << main[i];
		if ((i + 1) < main.size())
			std::cout << ", ";
	}
	std::cout << "]\npend: [";
	for (size_t i = 0; i < pend.size(); i++)
	{
		std::cout << pend[i];
		if ((i + 1) < pend.size())
			std::cout << ", ";
	}
	std::cout << "]" << std::endl;

	// Insert pend into main

}

size_t PmergeMe::calculateJacobsthal(size_t n)
{
	if (n == 0 || n == 1)
		return (n);
	return calculateJacobsthal(n - 1) + (2 * calculateJacobsthal(n - 2));
}

int	PmergeMe::binarySearch(std::vector<int>& intVec, int n)
{
	int l = 0;
	int r = intVec.size() - 1;

	while (l <= r)
	{
		int m  = (l + r) / 2;
		if (intVec[m] == n)
		{
			return m;
		}
		if (n < intVec[m])
		{
			std::cout << n << " < " << intVec[m] << std::endl;
			std::cout << "r = " << m  << std::endl;
			r = m - 1;
		}
		else if (n > intVec[m])
		{
			std::cout << n << " > " << intVec[m] << std::endl;
			std::cout << "l = " << m  << std::endl;
			l = m + 1;
		}
	}
	return (-1);
}

