#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* a1 = new Dog();
	const Animal* a2 = new Cat();

	std::cout << "(a1) I'm a " << a1->getType() << std::endl;
	std::cout << "(a2) I'm a " << a2->getType() << std::endl;

	a1->makeSound();
	a2->makeSound();
	meta->makeSound();

	return (0);
}
