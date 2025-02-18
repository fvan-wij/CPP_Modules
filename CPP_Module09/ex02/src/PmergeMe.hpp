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
		static void	merge(std::vector<int>& elements, size_t low, size_t mid, size_t high);
		static void	merge(std::vector<std::pair<int, int>>& pairs, size_t low, size_t mid, size_t high);

		static void	mergeSort(std::vector<int>&	elements, size_t low, size_t high);
		static void	mergeSort(std::vector<std::pair<int, int>>&	elements, size_t low, size_t high);

		static void mergeInsertionSort(std::vector<int>& elements);
		static size_t calculateJacobsthal(size_t n);
		static int	binaryInsertion(std::vector<int>& intVec, int n);

	private:
};
