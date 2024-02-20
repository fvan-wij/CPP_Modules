#include <iostream>
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
	Animal* arr[4] = {new Cat(), new Cat(), new Dog(), new Dog()};

	arr[3]->makeSound();

	// for (size_t i = 0; i < 4; i++) {
	// 	delete arr[i];
	// }


	arr[1]->getBrain()->setIdea(0, "I could eat a mouse...");
	arr[0] = arr[1];
	arr[1]->getBrain()->setIdea(0, "I could eat a fish...");
	std::cout << arr[0]->getBrain()->getIdea(0) << std::endl;

	return (0);
}
