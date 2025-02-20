#include <iostream>
#include <vector>

#include "PmergeMe.hpp"



int main(int argc, char *argv[])
{
	if (argc <= 1)
	{
		std::cerr << "Error: Program requires a sequence of positive integers in order to run" << std::endl;
	}

	std::vector<int> intVec;
	size_t i = 1;
	while (argv[i])
	{
		try 
		{
			int	number = std::stoi(argv[i]);
			intVec.push_back(number);
		}
		catch (std::exception& e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
			return 1;
		}
		i++;
	}
	PmergeMe::mergeInsertionSort(intVec);
	// auto it = std::lower_bound(intVec.begin(), intVec.end(), 0);
	// intVec.insert(it, 0);
	// std::cout <<  *it << std::endl;
	// printNumbers(intVec);

}
