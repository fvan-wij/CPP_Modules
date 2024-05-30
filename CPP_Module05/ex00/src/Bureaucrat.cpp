#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _NAME("Default"), _grade(150)
{
	std::cout << "(Default constructor) ";
	std::cout 	<< "Default Bureaucrat has been hired. "
		<< "Grade: " 
		<< _grade 
		<< std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _NAME(name), _grade(grade)
{
	std::cout << "(Constructor) ";
	if (grade > MIN_GRADE)
		throw (GradeTooLowException());
	else if (grade < MAX_GRADE)
		throw (GradeTooHighException());
	std::cout 	<< "A new Bureaucrat has been hired. Name: "
		<< _NAME 
		<< ", grade: " 
		<< _grade 
		<< std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _NAME(other._NAME), _grade(other._grade)
{
	std::cout << "(Copy constructor) ";
	if (other._grade > MIN_GRADE)
		throw (GradeTooHighException());
	else if (other._grade > MAX_GRADE)
		throw (GradeTooLowException());
	std::cout 	<< "A doppelganger has been hired. Name: "
		<< _NAME 
		<< ", grade: " 
		<< _grade 
		<< std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "(Assignment operator) ";
	std::cout 	<< "Assigning " 
		<< other._NAME 
		<< "'s grade to " 
		<< this->_NAME 
		<< std::endl;
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
		std::cout 	<< "Bureaucrat "
			<< _NAME 
			<< "'s grade has been changed from " 
			<< _grade 
			<< " to " 
			<< grade 
			<< std::endl;
			this->_grade = grade;
	};
}

void Bureaucrat::getGrade() const
{
	std::cout 	<< "Bureaucrat "
		<< _NAME 
		<< "'s grade is " 
		<< _grade 
		<< std::endl;
}

void Bureaucrat::getName() const
{
	std::cout 	<< "Bureaucrat's name is: "
		<< _NAME 
		<< std::endl;
}

void Bureaucrat::incrementGrade()
{
	std::cout 	<< "(Incrementing..) ";
	this->setGrade(_grade - 1);
}

void Bureaucrat::decrementGrade()
{
	std::cout 	<< "(Decrementing..) ";
	this->setGrade(_grade + 1);
}

Bureaucrat::~Bureaucrat()
{
	std::cout 	<< "It's 5pm! " 
		<< _NAME 
		<< " is going home." 
		<< std::endl;
}


const char* Bureaucrat::GradeTooLowException::what() const throw() 
{
	return ("Computer says NO: Grade is too low");
}

const char* Bureaucrat::GradeTooHighException::what() const throw() 
{
	return ("Computer says NO: Grade is too high");
}
