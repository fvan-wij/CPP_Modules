#pragma once

#include <vector>

class PmergeMe
{
	public:
		PmergeMe(const std::vector<int>& intVec);
		~PmergeMe();

		std::vector<int>	sort(std::vector<int>	elements);

	private:
		std::vector<int>						_intVec;
		std::size_t								_leftover;
};
