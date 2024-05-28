#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	// Bureaucrat dflt;
	Bureaucrat	*bob;

	// try {
	// 	bob = new Bureaucrat("Bob", 155);
	// }
	// catch (const Bureaucrat::GradeTooLowException& e) {
	// 	std::cerr << "Exception caught: " << e.what() << std::endl;
	// }
	// catch (const Bureaucrat::GradeTooHighException& e) {
	// 	std::cerr << "Exception caught: " << e.what() << std::endl;
	// }

	try {
		bob = new Bureaucrat("Bob", 100);
		bob->getGrade();
		// bob->setGrade(150);
	}
	catch (const Bureaucrat::GradeTooLowException& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try {
		bob->setGrade(150);
	}
	catch (const Bureaucrat::GradeTooLowException& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	bob->decrementGrade();

	// dflt = *bob;
	// try {
	// 	bob->setGrade(155);
	// }
	// catch (const Bureaucrat::GradeTooLowException& e) {
	// 	std::cerr << "Exception caught: " << e.what() << std::endl;
	// }
	// catch (const Bureaucrat::GradeTooHighException& e) {
	// 	std::cerr << "Exception caught: " << e.what() << std::endl;
	// }
	return (0);
}
