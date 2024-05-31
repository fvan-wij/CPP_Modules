#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	Bureaucrat	*bob;

	//	Test 1: Instantiating a Bureaucrat with a grade that's too low;
	// try {
	// 	bob = new Bureaucrat("Bob", 151);
	// }
	// catch (const Bureaucrat::GradeTooLowException& e) {
	// 	std::cerr << "Exception caught: " << e.what() << std::endl;
	// 	return (1);
	// }
	// catch (const Bureaucrat::GradeTooHighException& e) {
	// 	std::cerr << "Exception caught: " << e.what() << std::endl;
	// 	return (1);
	// }
	// bob->getGrade();

	// Test 2: Setting the grade to an invalid number
	// try {
	// 	bob = new Bureaucrat("Bob", 50);
	// 	bob->setGrade(151);
	// }
	// catch (const Bureaucrat::GradeTooLowException& e) {
	// 	std::cerr << "Exception caught: " << e.what() << std::endl;
	// 	delete (bob);
	// 	return (1);
	// }
	// catch (const Bureaucrat::GradeTooHighException& e) {
	// 	std::cerr << "Exception caught: " << e.what() << std::endl;
	// 	delete (bob);
	// 	return (1);
	// }
	// bob->getGrade();

	// Test 3: 
	Bureaucrat dflt;
	try {
		bob = new Bureaucrat("Bob", 150);
		std::cout << dflt << std::endl;
		dflt = *bob;
		dflt.getGrade();
		dflt.setGrade(149);
		dflt.decrementGrade();
		dflt.decrementGrade();
		// dflt.incrementGrade();
		// dflt.incrementGrade();
		dflt.getGrade();
		// bob->setGrade(155);
	}
	catch (const Bureaucrat::GradeTooLowException& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
		delete bob;
		return (1);
	}
	catch (const Bureaucrat::GradeTooHighException& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
		delete bob;
		return (1);
	}
	return (0);
}
