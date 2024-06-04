#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>

void testDing()
{
	Intern	unpaid_intern;
    AForm*	form;

	try
	{
		form = unpaid_intern.makeForm("fake form", "Bender");
		std::cout << *form;
		form = unpaid_intern.makeForm("not a form", "Bender");
		std::cout << *form;
	}
	catch (std::exception& exception)
	{
		std::cerr << "An exception was caught! " << exception.what();
	}
}

int main()
{
	testDing();
	return (0);
}
