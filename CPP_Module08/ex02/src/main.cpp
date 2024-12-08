#include <iostream>
#include "MutantStack.hpp"

void	subjectTest()
{
	std::cout << "--Subject test" << std::endl;

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
	std::cout << "Testing iterators (old school)" << std::endl;
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

int main(void)
{
	subjectTest();
}
