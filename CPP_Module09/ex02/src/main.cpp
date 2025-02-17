#include <iostream>
#include <vector>

#include "PmergeMe.hpp"


static void	printNumbers(std::vector<int>& vec)
{
	for (int n : vec)
	{
		std::cout << n << ", ";
	}
	std::cout << std::endl;
}

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
	// PmergeMe::mergeSort(intVec, 0, intVec.size() - 1);
	printNumbers(intVec);
	// std::cout << "Jacobsthal n is: " << PmergeMe::calculateJacobsthal(intVec[0]) << std::endl;
	// int n = 100;
	// std::cout << "Index of " <<  n << " is: " << PmergeMe::binarySearch(intVec, n) << std::endl;
	// std::cout << PmergeMe::binarySearch(intVec, n) << std::endl;
}
