#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

void	testShrubberyForm()
{
	
	{	//Successful
		ShrubberyCreationForm	shrubForm("Tree");
		Bureaucrat				bc("The President", 1);

		bc.signForm(shrubForm);
		bc.executeForm(shrubForm);
	}
	{	//Not signed
		ShrubberyCreationForm	shrubForm("Struikje");
		Bureaucrat				bc("Noob", 150);

		bc.executeForm(shrubForm);
	}
	{	//Low grade
		ShrubberyCreationForm	shrubForm("Boompje");
		Bureaucrat				bc("Bob", 144);

		bc.signForm(shrubForm);
		bc.executeForm(shrubForm);
	}
}

void	testRobotomyForm()
{
	{	//Succesful
		RobotomyRequestForm		robotForm("Subject 617");
		Bureaucrat				bc("Krüger", 1);

		bc.signForm(robotForm);
		bc.executeForm(robotForm);
	}
	{	//Not signed
		RobotomyRequestForm		robotForm("Subject 617");
		Bureaucrat				bc("Krüger", 1);

		bc.executeForm(robotForm);
	}
	{	//Low grade
		RobotomyRequestForm		robotForm("Subject 617");
		Bureaucrat				bc("Krüger", 70);

		bc.signForm(robotForm);
		bc.executeForm(robotForm);
	}
}

void	testPresidentialForm()
{
	{	//Succesful
		PresidentialPardonForm		presForm("Excus've'nt");
		Bureaucrat					bc("The dude", 1);

		bc.signForm(presForm);
		bc.executeForm(presForm);
	}
	{	//Not signed
		PresidentialPardonForm		presForm("Excus've'nt");
		Bureaucrat					bc("The dude", 1);

		bc.executeForm(presForm);
	}
	{	//Low grade
		PresidentialPardonForm		presForm("Excus've'nt");
		Bureaucrat					bc("The dude", 20);

		bc.signForm(presForm);
		bc.executeForm(presForm);
	}
}

int main()
{
	// testShrubberyForm();
	// testRobotomyForm();
	testPresidentialForm();
	return (0);
}
