#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : _NAME("Default"), _grade(150)
{
	logDebug(GREEN, "(Default constructor) A Default bureaucrat has been hired." + std::to_string(_grade));
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _NAME(name), _grade(grade)
{
	if (grade > MIN_GRADE)
		throw (GradeTooLowException());
	else if (grade < MAX_GRADE)
		throw (GradeTooHighException());
	logDebug(GREEN, "(Constructor) Bureaucrat " + _NAME + " has been hired. Grade: " + std::to_string(_grade));
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _NAME(other._NAME), _grade(other._grade)
{
	if (other._grade > MIN_GRADE)
		throw (GradeTooHighException());
	else if (other._grade > MAX_GRADE)
		throw (GradeTooLowException());
	logDebug(GREEN, "(Copy constructor) Doppelgänger " + _NAME + " has been hired. Grade: " + std::to_string(_grade));
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	logDebug(GREEN, "(Assignment operator) Assigning " + other._NAME + "'s grade to " + this->_NAME);
	try {
		this->setGrade(other._grade);
	} catch (const GradeTooLowException& e) {
		std::cerr << "Exception caught while setting grade: " << e.what() << std::endl;
	} catch (const GradeTooHighException& e) {
		std::cerr << "Exception caught while setting grade: " << e.what() << std::endl;
	}
	return (*this);
}

void Bureaucrat::setGrade(int grade)
{
	if (grade > MIN_GRADE)
		throw (GradeTooLowException());
	else if (grade < MAX_GRADE)
		throw (GradeTooHighException());
	else
	{
		logDebug(GREEN, "Bureaucrat " + _NAME + "'s grade has been changed from " + std::to_string(_grade) + " to " + std::to_string(_grade));
		this->_grade = grade;
	};
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

std::string Bureaucrat::getName() const
{
	return (_NAME);
}

void Bureaucrat::incrementGrade()
{
	logDebug(GREEN, "(Incrementing...)");
	this->setGrade(_grade - 1);
}

void Bureaucrat::decrementGrade()
{
	logDebug(GREEN, "(Decrementing...)");
	this->setGrade(_grade + 1);
}

void Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
	}
	catch (const std::exception& e)
	{
		std::cout << this->_NAME << " could not sign " << form.getName() << " because: " << e.what() << std::endl;
	}
}

Bureaucrat::~Bureaucrat()
{
	logDebug(RED, "(Deconstructor) It's 5pm! " + _NAME + " is going home.");
}

void Bureaucrat::logDebug(std::string col, std::string msg)
{
	std::cout << col << msg << "\033[0m\t\t" << std::endl;
}

const char* Bureaucrat::GradeTooLowException::what() const throw() 
{
	return ("\x1B[33mComputer says NO: Grade is too low\033[0m\t\t");
}

const char* Bureaucrat::GradeTooHighException::what() const throw() 
{
	return ("\x1B[33mComputer says NO: Grade is too high\033[0m\t\t");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	return (os << b.getName() << ", bureaucrat grade " << b.getGrade());
}
