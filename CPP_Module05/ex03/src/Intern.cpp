#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	logDebug(GREEN, "(Constructor) A new intern has been hired");
}

Intern::Intern(const Intern& other)
{
	logDebug(GREEN, "(Constructor) A new intern has been cloned");
	*this = other;
}

Intern& Intern::operator=(const Intern& other)
{
	logDebug(GREEN, "(Copy assignment operator) A new intern has been cloned");
	(void) other;
	return (*this);
}

Intern::~Intern()
{
	logDebug(RED, "~(Deconstructor) It's 5 pm! Time for the intern to go home!");
}

AForm	*makeForm(std::string name, std::string target)
{
	const std::string 	forms[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	uint8_t 			formId;

	for (formId = 0; formId < 3; formId++)
	{
		if (name == forms[formId])
			break ;
	}
	switch (formId)
	{
		case 0:
			  return (new ShrubberyCreationForm(target));
		case 1:
			  return (new RobotomyRequestForm(target));
		case 2:
			  return (new PresidentialPardonForm(target));
		default:
			  throw (Intern::FormDoesNotExistException());
	}
}

const char* Intern::FormDoesNotExistException::what() const throw()
{
	return ("Form does not exist");
}

void	Intern::logDebug(std::string col, std::string msg)
{
	std::cout << col << msg << "\033[0m\t\t" << std::endl;
}
