#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	logDebug(GREEN, "(Constructor) ShrubberyCreationForm created");
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target)
{
	logDebug(GREEN, "(Copy constructor) ShrubberyCreationForm copied");
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	logDebug(RED, "~(Deconstructor) ShrubberyCreationForm destroyed");
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	logDebug(GREEN, "(Copy assignment operator) copied data from another form.");
	AForm::operator=(other);
	this->_target = other._target;
	return (*this);
}

void		ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	AForm::execute(executor);
	std::ofstream file(this->_target + "_shrubbery");
    file 	  << "    *\n"
                 "   ***\n"
                 "  *****\n"
                 "   ***\n"
                 "  *****\n"
                 " *******\n"
                 "*********\n"
                 "   ***\n";
	file.close();
	std::cout << "Shrubbery has been created in " << this->_target << "_shrubbery" << std::endl;
}
