#include "Form.hpp"

Form::Form() : _NAME("Default"), _grade(150)
{
	std::cout << "(Default constructor) ";
	std::cout 	<< "Default Form has been hired. "
		<< "Grade: " 
		<< _grade 
		<< std::endl;
}

Form::Form(const std::string name, int grade) : _NAME(name), _grade(grade)
{
	std::cout << "(Constructor) ";
	if (grade > MIN_GRADE)
		throw (GradeTooLowException());
	else if (grade < MAX_GRADE)
		throw (GradeTooHighException());
	std::cout 	<< "A new Form has been hired. Name: "
		<< _NAME 
		<< ", grade: " 
		<< _grade 
		<< std::endl;
}

Form::Form(const Form& other) : _NAME(other._NAME), _grade(other._grade)
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

Form& Form::operator=(const Form& other)
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

void Form::setGrade(int grade)
{
	if (grade > MIN_GRADE)
		throw (GradeTooLowException());
	else if (grade < MAX_GRADE)
		throw (GradeTooHighException());
	else
	{
		std::cout 	<< "Form "
			<< _NAME 
			<< "'s grade has been changed from " 
			<< _grade 
			<< " to " 
			<< grade 
			<< std::endl;
			this->_grade = grade;
	};
}

int Form::getSignGrade() const
{
	return (_SIGN_GRADE);
}

int Form::getExecGrade() const
{
	return (_EXEC_GRADE);
}

std::string Form::getName() const
{
	return (_NAME);
}

Form::~Form()
{
	std::cout 	<< "It's 5pm! " 
		<< _NAME 
		<< " is going home." 
		<< std::endl;
}

const char* Form::GradeTooLowException::what() const throw() 
{
	return ("Computer says NO: Grade is too low");
}

const char* Form::GradeTooHighException::what() const throw() 
{
	return ("Computer says NO: Grade is too high");
}

std::ostream& operator<<(std::ostream& os, const Form& b)
{
	return (os << b.getName() << ", bureaucrat grade " << b.getGrade());
}

