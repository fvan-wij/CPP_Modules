#pragma once

#include <vector>
#include <cstddef>


enum SubArray {
	Left,
	Right,
};

class PmergeMe
{
	public:
		PmergeMe() = delete;

		static std::vector<int>	sort(std::vector<int>&	elements);

		template<typename T>
			static void merge(T pairs, size_t low, size_t mid, size_t high);

		template<typename T>
			static void mergeSort(T& elements, size_t low, size_t high);

		static void mergeInsertionSort(std::vector<int>& elements);
		static size_t calculateJacobsthal(size_t n);
		static int	binaryInsertion(std::vector<int>& intVec, int n);

	private:
};

template <typename T>
void PmergeMe::mergeSort(T& elements, size_t low, size_t high)
{
	if (low >= high)
		return;

	size_t	mid = (low + high) / 2;

	mergeSort(elements, low, mid);
	mergeSort(elements, mid + 1, high);
	merge(elements, low, mid, high);
}


template <typename T>
void	PmergeMe::merge(T pairs, size_t low, size_t mid, size_t high)
{
	T	subarrayL(pairs.begin() + low, pairs.begin() + mid + 1);
	T	subarrayR(pairs.begin() + mid + 1, pairs.begin() + high + 1);

	// std::cout << "low: " << low << ", mid: " << mid << ", high: " << high << std::endl;

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
