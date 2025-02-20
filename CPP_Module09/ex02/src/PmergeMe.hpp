#pragma once

#include <vector>
#include <cstddef>
#include <deque>
#include <chrono>
#include <iostream>
#include <algorithm>

enum SubArray {
	Left,
	Right,
};

class PmergeMe
{
	public:
		PmergeMe() = delete;

		template<typename T>
			static void mergeInsertionSort(T& elements);

	private:
		// Sorting
		template<typename T>
			static void merge(T& pairs, size_t low, size_t mid, size_t high);

		template<typename T>
			static void mergeSort(T& pairs, size_t low, size_t high);

		// Utility
		static size_t calculateJacobsthal(size_t n);
		static int	binaryInsertion(std::vector<int>& intVec, int n);

		template <typename T>
			static void	printContainer(const T& container);

		template <typename T>
			static void printPairs(const T& container);

};

template <typename T>
void	PmergeMe::printContainer(const T& container)
{
	for (auto it = container.begin(); it != container.end(); it++)
	{
		std::cout << *it;
		if (std::next(it) != container.end())
			std::cout << " ";
	}
	std::cout << std::endl;
}

template <typename T>
void PmergeMe::printPairs(const T& container)
{
	std::cout << "Pairs: ";
	for (const auto& element : container)	
	{
		std::cout << "[" << element.first << ", " << element.second << "]";
	}
	std::cout << std::endl;
}


template <typename T>
void PmergeMe::mergeSort(T& pairs, size_t low, size_t high)
{
	if (low >= high)
		return;

	size_t	mid = (low + high) / 2;

	mergeSort(pairs, low, mid);
	mergeSort(pairs, mid + 1, high);
	merge(pairs, low, mid, high);
}


template <typename T>
void	PmergeMe::merge(T& pairs, size_t low, size_t mid, size_t high)
{
	T	subarrayL(pairs.begin() + low, pairs.begin() + mid + 1);
	T	subarrayR(pairs.begin() + mid + 1, pairs.begin() + high + 1);

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

template <typename T>
void PmergeMe::mergeInsertionSort(T& elements)
{
	std::cout << "Before: ";
	printContainer(elements);

	std::chrono::high_resolution_clock::time_point startTime = std::chrono::high_resolution_clock::now();
	int oddOne = -1;

	// Group into n/2 pairs
	if (elements.size() % 2 == 1)
	{
		oddOne = elements.back();
		elements.pop_back();
	}

	// Check if T is vector or deque
	using PairContainer = typename std::conditional< 
		std::is_same<T, std::vector<int>>::value, // Condition
		std::vector<std::pair<int, int>>, // Type if true (TrueType)
		std::deque<std::pair<int, int>> // Type if false (FalseType)
		>::type;

	PairContainer pairs;

	for (auto it = elements.begin(); it != elements.end(); it++)
	{
		std::pair p {*it, *(++it)};
		if (p.first < p.second)
			std::swap(p.first, p.second);
		pairs.insert(pairs.end(), p);
	}

	// Recursively sort pairs based on the first number
	mergeSort(pairs, 0, pairs.size() - 1);


	// Create main and pend chain
	T main, pend;
	for (auto it = pairs.begin(); it != pairs.end(); it++)
	{
		main.insert(main.end(), it->first);
		pend.insert(pend.end(), it->second);
	}

	// Insert first pending element into main (pend[0] corresponds to first n in sorted pair container)
	main.insert(main.begin(), pend[0]);
	pend.erase(pend.begin());

	// Create Jacobsthal sequence based on size of pair container size
	T jacobsthalSequence;
	for (size_t i = 0; i < main.size(); i++)
	{
		jacobsthalSequence.push_back(calculateJacobsthal(i));
	}

	// From pend array, take pend[jacobsth] and use binary insertion
	// Insert numbers from pend chain in Jacobsthal's order
	for (int& jacobsth : jacobsthalSequence)
	{
		if ((size_t)jacobsth < pend.size())
		{
			auto numberToInsert = pend[jacobsth];
			auto itIndex = std::lower_bound(main.begin(), main.end(), numberToInsert);
			main.insert(itIndex, numberToInsert);
			auto it = std::find(pend.begin(), pend.end(), numberToInsert);
			if (it != pend.end())
				pend.erase(it);
		}
	}

	// Insert remaining elements from pend chain
	for (auto & itNumber : pend)
	{
		auto it = std::lower_bound(main.begin(), main.end(), itNumber);
		main.insert(it, itNumber);
	}	

	// Insert odd number
	if (oddOne != -1)
	{
		auto it = std::lower_bound(main.begin(), main.end(), oddOne);
		main.insert(it, oddOne);
	}

	std::chrono::high_resolution_clock::time_point endTime = std::chrono::high_resolution_clock::now();
	elements = main;
    double deltaTime = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime).count();
	deltaTime /= 10000;

	std::cout << "After: ";
	printContainer(elements);
	if constexpr (std::is_same<PairContainer, std::vector<std::pair<int, int>>>::value)
	{
		std::cout << "Time to process a range of " << elements.size() << " elements with std::vector<int> : " << deltaTime << " us\n" << std::endl;
	}
	else if constexpr (std::is_same<PairContainer, std::deque<std::pair<int, int>>>::value)
	{
		std::cout << "Time to process a range of " << elements.size() << " elements with std::deque<int> : " << deltaTime << " us" << std::endl;
	}
}
