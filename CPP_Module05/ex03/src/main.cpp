#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>

void testUnknownForm()
{
	Intern	intern;
    AForm*	form;

	try
	{
		form = intern.makeForm("fake form", "Bloop");
		std::cout << *form << std::endl;
		form = intern.makeForm("not a form", "Barry");
		std::cout << *form << std::endl;
	}
	catch (std::exception& exception)
	{
		std::cerr << "An exception was caught: " << exception.what();
	}
}

void testKnownForm()
{
	Intern	intern;
    AForm*	form;

	try
	{
		form = intern.makeForm("shrubbery creation", "Bloop");
		std::cout << *form << std::endl;
		delete form;
		form = intern.makeForm("robotomy request", "Barry");
		std::cout << *form << std::endl;
		delete form;
		form = intern.makeForm("presidential pardon", "Larry");
		std::cout << *form << std::endl;
		delete form;
	}
	catch (std::exception& exception)
	{
		std::cerr << "An exception was caught: " << exception.what();
	}
}

void testMakeFormWithSignAndExecution()
{
	Intern		intern;
	Bureaucrat	president("Zaphod Beeblebox", 1);
    AForm*		form;

	try
	{
		form = intern.makeForm("presidential pardon", "Larry");
		president.signForm(*form);
		president.executeForm(*form);
		delete form;
		// std::cout << *form << std::endl;

	}
	catch (std::exception& exception)
	{
		std::cerr << "An exception was caught: " << exception.what();
	}
}

int main()
{
	// testUnknownForm();
	// testKnownForm();
	testMakeFormWithSignAndExecution();

	return (0);
}
