#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

void testSignTooLow()
{
	Bureaucrat	bc("Bob", 150);
	Form		form("Important form", 50, 50);

	bc.signForm(form);
}

void testSignSuccesful()
{
	Bureaucrat bc("Bob", 30);
	Form form("Not-so-important-form", 30, 150);
	bc.signForm(form);
}

void testConstructorTooLowSignGrade()
{
	try
	{
		Form form("Form", 151, 40);
	}
	catch (std::exception& exception)
	{
		std::cerr << "An exception was caught! " << exception.what() << std::endl;
	}

	try
	{
		Form form("Form", 20, 151);
	}
	catch (std::exception& exception)
	{
		std::cerr << "An exception was caught! " << exception.what() << std::endl;
	}
}

void testConstructorTooHighSignGrade()
{
	try
	{
		Form form("Form", 0, 40);
	}
	catch (std::exception& exception)
	{
		std::cerr << "An exception was caught! " << exception.what() << std::endl;
	}

	try
	{
		Form form("Form", 20, 0);
	}
	catch (std::exception& exception)
	{
		std::cerr << "An exception was caught! " << exception.what() << std::endl;
	}
}

void testConstructors(void)
{
	Bureaucrat bob("Bob", 100);
	Form boring("Not-so-important-form", 150, 150);
	Form exciting("Very-important-form", 1, 1);
	std::cout << boring << std::endl;
	std::cout << exciting << std::endl;
	Form copyform(exciting);
	boring.beSigned(bob);
	copyform = boring;
	std::cout << copyform << std::endl;
}

int main()
{
	testConstructors();
	// testSignTooLow();
	// testSignSuccesful();
	// testConstructorTooLowSignGrade();
	// testConstructorTooHighSignGrade();
	return (0);
}
