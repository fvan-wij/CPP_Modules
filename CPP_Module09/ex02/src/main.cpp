#include <iostream>
#include <vector>

#include "PmergeMe.hpp"

int	fillContainers(std::vector<int>& intVec, std::deque<int>& intDeque, char* argv[])
{
	size_t i = 1;
	while (argv[i])
	{
		try 
		{
			int	number = std::stoi(argv[i]);
			if (number < 0)
				throw std::invalid_argument("Received negative integer");
			intVec.push_back(number);
			intDeque.push_back(number);
		}
		catch (std::exception& e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
			return 1;
		}
		i++;
	}
	if (intVec.size() == 1 || intDeque.size() == 1)
	{
		std::cerr << "Error: integer list must contain at least 2 numbers" << std::endl;
		return 2;
	}
	return 0;
}

int main(int argc, char *argv[])
{
	if (argc <= 1)
	{
		std::cerr << "Error: Program requires a sequence of positive integers in order to run" << std::endl;
		return 1;
	}

	std::vector<int> intVec;
	std::deque<int> intDeque;

	if (fillContainers(intVec, intDeque, argv) != 0)
	{
		return 1;
	}

	try 
	{
		PmergeMe mergeObject;
		mergeObject.mergeInsertionSort(intVec);
		mergeObject.mergeInsertionSort(intDeque);
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 2;
	}
	return 0;
}
