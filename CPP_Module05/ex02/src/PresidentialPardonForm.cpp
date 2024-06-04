#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	logDebug(GREEN, "(Constructor) PresidentialPardonForm created");
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), _target(other._target)
{
	logDebug(GREEN, "(Copy constructor) PresidentialPardonForm copied");
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	logDebug(RED, "~(Deconstructor) PresidentialPardonForm destroyed");
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	logDebug(GREEN, "(Copy assignment operator) copied data from another form.");
	AForm::operator=(other);
	this->_target = other._target;
	return (*this);
}

void		PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	AForm::execute(executor);
	std::cout << _target << " has been pardoned by Zaphod Beeblebox." << std::endl;
}
