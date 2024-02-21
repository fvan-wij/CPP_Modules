#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{

	//Test using the animal base class pointing to a derived class
	Animal* arr[4] = {new Cat(), new Cat(), new Dog(), new Dog()};

	arr[1]->getBrain()->setIdea(0, "I could eat a mouse...");

	//Trick I found to call the copy assignment operator of the Cat class (which is necessary to make a deep copy of the Brain attribute). 
	//If I don't type cast it, the Animal copy assignment operator gets called instead... 
	//My first intuition was to make the copy assignment operator virtual, so that the most derived version of the assignment operator would get called (from the Cat sub class). 
	//This did not do the trick, perhaps the evaluator knows a better way?
	*static_cast<Cat*>(arr[0]) = *static_cast<Cat*>(arr[1]);

	arr[1]->getBrain()->setIdea(0, "I could eat a fish...");

	std::cout << arr[0]->getBrain()->getIdea(0) << std::endl;

	for (size_t i = 0; i < 4; i++) {
		delete arr[i];
	}


	//Test using derived classes
	Cat* cate = new Cat();

	cate->getBrain()->setIdea(0, "Pass brokje");
	Cat* kat = new Cat(*cate);
	cate->getBrain()->setIdea(0, "Pass tonijn");
	std::cout << kat->getBrain()->getIdea(0) << std::endl;

	delete cate;
	delete kat;

	return (0);
}
