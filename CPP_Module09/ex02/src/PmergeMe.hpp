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
		PmergeMe();
		~PmergeMe();

		std::vector<int>	sort(std::vector<int>&	elements);
		void	merge(std::vector<int>& elements, size_t low, size_t mid, size_t high);
		void	mergeSort(std::vector<int>&	elements, size_t low, size_t high);

	private:
};
