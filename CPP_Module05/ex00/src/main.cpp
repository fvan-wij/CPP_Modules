#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	Bureaucrat dflt;
	Bureaucrat	*bob;

	bob = new Bureaucrat("Bob", 155);
	// try {
	// 	bob->setGrade(155);
	// }
	// catch (const Bureaucrat::GradeTooLowException& e) {
	// 	std::cerr << "Exception caught: " << e.what() << std::endl;
	// }
	// catch (const Bureaucrat::GradeTooHighException& e) {
	// 	std::cerr << "Exception caught: " << e.what() << std::endl;
	// }

	dflt = *bob;
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
