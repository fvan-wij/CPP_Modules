#include "PmergeMe.hpp"
#include <cstddef>

PmergeMe::PmergeMe()
{

}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	(void) other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this == &other)
		return *this;

	return *this;
}

PmergeMe::~PmergeMe()
{

}

size_t PmergeMe::_calculateJacobsthal(size_t n)
{
	if (n == 0 || n == 1)
	{
		return (n);
	}
	return _calculateJacobsthal(n - 1) + (2 * _calculateJacobsthal(n - 2));
}

int	PmergeMe::_binaryInsertion(std::vector<int>& intVec, int n)
{
	int l = 0;
	int r = intVec.size() - 1;
	int m = 0;

	while (l <= r)
	{
		m = (l + r) / 2;
		if (intVec[m] == n)
		{
			return m + 1;
		}
		if (n < intVec[m])
		{
			r = m - 1;
		}
		else if (n > intVec[m])
		{
			l = m + 1;
		}
	}
	return (l);
}
