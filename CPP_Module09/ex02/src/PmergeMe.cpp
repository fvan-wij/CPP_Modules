#include "PmergeMe.hpp"
#include <cstddef>

size_t PmergeMe::calculateJacobsthal(size_t n)
{
	if (n == 0 || n == 1)
		return (n);
	return calculateJacobsthal(n - 1) + (2 * calculateJacobsthal(n - 2));
}

int	PmergeMe::binaryInsertion(std::vector<int>& intVec, int n)
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
