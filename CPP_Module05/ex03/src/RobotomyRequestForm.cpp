#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	logDebug(GREEN, "(Constructor) RobotomyRequestForm created");
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other._target)
{
	logDebug(GREEN, "(Copy constructor) RobotomyRequestForm copied");
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	logDebug(RED, "~(Deconstructor) RobotomyRequestForm destroyed");
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	logDebug(GREEN, "(Copy assignment operator) copied data from another form.");
	AForm::operator=(other);
	this->_target = other._target;
	return (*this);
}

void		RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	AForm::execute(executor);
	srand(time(nullptr));
	const float chance = (static_cast<float>(rand()) / static_cast<float>(RAND_MAX));
	if (chance >= 0.5f)
		std::cout << "*DRILLING NOISES* " << _target << " has been robotomized succesfully!" << std::endl;
}
