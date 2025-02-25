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

const size_t JACOBSTHAL_SEQUENCE[] = {
	0, 1, 1, 3, 5, 11, 21, 43,
	85, 171, 341, 683, 1365, 2731,
	5461, 10923, 21845, 43691, 87381,
	174763, 349525, 699051, 1398101, 2796203,
	5592405, 11184811, 22369621, 44739243, 89478485,
	178956971, 357913941, 715827883, 1431655765, 2863311531,
	5726623061, 11453246123
};

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		template<typename T>
			void mergeInsertionSort(T& elements);

	private:
		size_t 	_calculateJacobsthal(size_t n);
		int		_binaryInsertion(std::vector<int>& intVec, int n);

		template<typename T>
			void _merge(T& pairs, size_t low, size_t mid, size_t high);
		template<typename T>
			void _mergeSort(T& pairs, size_t low, size_t high);

		template <typename T>
			void _printContainer(const T& container);

		template <typename T>
			void _printPairs(const T& container);
};

template <typename T>
void PmergeMe::mergeInsertionSort(T& elements)
{
	std::cout << "Before: ";
	_printContainer(elements);

	std::chrono::high_resolution_clock::time_point startTime = std::chrono::high_resolution_clock::now();
	int oddOne = -1;

	// Group into n/2 pairs
	if (elements.size() % 2 == 1)
	{
		oddOne = elements.back();
		elements.pop_back();
	}
	using PairContainer = typename std::conditional< 
		std::is_same<T, std::vector<int>>::value, // Condition
		std::vector<std::pair<int, int>>, // Type if true (TrueType)
		std::deque<std::pair<int, int>> // Type if false (FalseType)
		>::type;

	PairContainer pairs;

	// Determine the larger of each pair
	for (auto it = elements.begin(); it != elements.end(); it++)
	{
		std::pair p {*it, *(++it)};
		if (p.first < p.second)
			std::swap(p.first, p.second);
		pairs.insert(pairs.end(), p);
	}

	// Recursively sort pairs based on the first number
	_mergeSort(pairs, 0, pairs.size() - 1);


	T main, pend;
	for (auto it = pairs.begin(); it != pairs.end(); it++)
	{
		main.insert(main.end(), it->first);
		pend.insert(pend.end(), it->second);
	}

	// Insert first pending element into main (pend[0] corresponds to first n in sorted pair container)
	main.insert(main.begin(), pend[0]);
	pend.erase(pend.begin());

	// From pend array, take pend[jacobsthal] and use binary insertion
	// Insert numbers from pend chain in Jacobsthal's order
	for (const size_t& jacobsthal : JACOBSTHAL_SEQUENCE)
	{
		if (jacobsthal < pend.size())
		{
			auto numberToInsert = pend[jacobsthal];
			auto itIndex = std::lower_bound(main.begin(), main.end(), numberToInsert);
			main.insert(itIndex, numberToInsert);
			auto it = std::find(pend.begin(), pend.end(), numberToInsert);
			if (it != pend.end())
				pend.erase(it);
		}
	}

	// Insert remaining elements from pend chain in reverse order
	for (auto itNumber = pend.rbegin(); itNumber != pend.rend(); itNumber++)
	{
		auto it = std::lower_bound(main.begin(), main.end(), *itNumber);
		main.insert(it, *itNumber);
	}	

	// Insert odd number
	if (oddOne != -1)
	{
		auto it = std::lower_bound(main.begin(), main.end(), oddOne);
		main.insert(it, oddOne);
	}

	std::chrono::high_resolution_clock::time_point endTime = std::chrono::high_resolution_clock::now();
	elements = main;
    double deltaTime = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
	deltaTime /= 10000;

	std::cout << "After: ";
	_printContainer(elements);
	if constexpr (std::is_same<PairContainer, std::vector<std::pair<int, int>>>::value)
	{
		std::cout << "Time to process a range of " << elements.size() << " elements with std::vector<int> : " << deltaTime << " μs\n" << std::endl;
	}
	else if constexpr (std::is_same<PairContainer, std::deque<std::pair<int, int>>>::value)
	{
		std::cout << "Time to process a range of " << elements.size() << " elements with std::deque<int> : " << deltaTime << " μs" << std::endl;
	}
}

template <typename T>
void	PmergeMe::_printContainer(const T& container)
{
	size_t counter = 0;
	for (auto it = container.begin(); it != container.end(); it++)
	{
		if (counter > 4)
		{
			std::cout << " [...]";
			break;
		}
		std::cout << *it;
		if (std::next(it) != container.end())
		{
			std::cout << " ";
		}
		counter++;
	}
	std::cout << std::endl;
}

template <typename T>
void PmergeMe::_printPairs(const T& container)
{
	std::cout << "Pairs: ";
	for (const auto& element : container)	
	{
		std::cout << "[" << element.first << ", " << element.second << "]";
	}
	std::cout << std::endl;
}


template <typename T>
void PmergeMe::_mergeSort(T& pairs, size_t low, size_t high)
{
	if (low >= high)
		return;

	size_t	mid = (low + high) / 2;

	_mergeSort(pairs, low, mid);
	_mergeSort(pairs, mid + 1, high);
	_merge(pairs, low, mid, high);
}


template <typename T>
void	PmergeMe::_merge(T& pairs, size_t low, size_t mid, size_t high)
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

