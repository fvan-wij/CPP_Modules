#include <iostream>
#include <list>
#include "MutantStack.hpp"

void	subjectTest()
{
	std::cout << "--Subject test with std::MutantStack" << std::endl;

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top: " << mstack.top() << "\n" << std::endl;
	mstack.pop();
	std::cout << "Size: " << mstack.size() << "\n" << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "Testing iterators" << std::endl;
	while (it != ite)
	{
		std::cout << *it << "\n";
		++it;
	}
	std::cout << std::endl;
	std::cout << "Testing iterators range based loop" << std::endl;
	for (auto &n : mstack)
	{
		std::cout << n << "\n";
	}
	std::cout << std::endl;
	std::stack<int> s(mstack);
}

void	subjectTestWithList()
{
	std::cout << "--Subject test with std::list" << std::endl;

	std::list<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << "Top: " << mstack.back() << "\n" << std::endl;
	mstack.pop_back();
	std::cout << "Size: " << mstack.size() << "\n" << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	mstack.push_back(0);
	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "Testing iterators" << std::endl;
	while (it != ite)
	{
		std::cout << *it << "\n";
		++it;
	}
	std::cout << std::endl;
	std::cout << "Testing iterators range based loop" << std::endl;
	for (auto &n : mstack)
	{
		std::cout << n << "\n";
	}
	std::cout << std::endl;
}

int main(void)
{
	subjectTest();
	subjectTestWithList();
}
