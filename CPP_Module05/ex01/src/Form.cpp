#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _NAME("Default"), _SIGN_GRADE(150), _EXEC_GRADE(150)
{
	logDebug(GREEN, "(Default constructor) A Default form has been created. Sign grade: " + std::to_string(_SIGN_GRADE) + ", execution grade: " + std::to_string(_EXEC_GRADE));
}

Form::Form(const std::string name, int signGrade, int execGrade) : _NAME(name), _SIGN_GRADE(signGrade), _EXEC_GRADE(execGrade)
{
	if (signGrade > MIN_GRADE || execGrade > MIN_GRADE)
		throw (GradeTooLowException());
	else if (signGrade < MAX_GRADE || execGrade < MAX_GRADE)
		throw (GradeTooHighException());

	this->_bSigned = false;
	logDebug(GREEN, "(Constructor) A new form has been created. Name: " + _NAME + ", sign grade: " + std::to_string(_SIGN_GRADE) + ", execution grade: " + std::to_string(_EXEC_GRADE));
}

Form::Form(const Form& other) : _NAME(other._NAME + " (copy)"), _SIGN_GRADE(other._SIGN_GRADE), _EXEC_GRADE(other._EXEC_GRADE), _bSigned(other._bSigned)
{
	if (other._SIGN_GRADE > MIN_GRADE || other._EXEC_GRADE > MIN_GRADE)
		throw (GradeTooHighException());
	else if (other._SIGN_GRADE < MAX_GRADE || other._EXEC_GRADE < MAX_GRADE)
		throw (GradeTooLowException());
	logDebug(GREEN, "(Copy constructor) A new form has been copied. Name: " + _NAME + ", sign grade: " + std::to_string(_SIGN_GRADE) + ", execution grade: " + std::to_string(_EXEC_GRADE));
}

Form& Form::operator=(const Form& other)
{
	logDebug(GREEN, "(Copy assignment operator) Assigning the signature from " + other._NAME + " to " + this->_NAME);
	this->_bSigned = other._bSigned;
	return (*this);
}

int Form::getSignGrade() const
{
	return (_SIGN_GRADE);
}

int Form::getExecGrade() const
{
	return (_EXEC_GRADE);
}

bool Form::isSigned() const
{
	return (_bSigned);
}

void Form::beSigned(Bureaucrat& bc)
{
	const int bcGrade = bc.getGrade();

	std::cout << bc << " is attempting to sign " << *this << std::endl;
	if (bcGrade > _SIGN_GRADE)
		throw (GradeTooLowException());
	std::cout << this->getName() << " has been signed by " << bc.getName() << std::endl;
	this->_bSigned = true;
}

std::string Form::getName() const
{
	return (_NAME);
}

Form::~Form()
{
	logDebug(RED, "(Deconstructor) *SHREDDING NOISE* Form " + _NAME + " has been destroyed");
}

const char* Form::GradeTooLowException::what() const throw() 
{
	return ("\x1B[33mComputer says NO: Grade is too low\033[0m\t\t");
}

const char* Form::GradeTooHighException::what() const throw() 
{
	return ("\x1B[33mComputer says NO: Grade is too high\033[0m\t\t");
}

void Form::logDebug(std::string col, std::string msg)
{
	std::cout << col << msg << "\033[0m\t\t" << std::endl;
}
std::ostream& operator<<(std::ostream& os, const Form& b)
{
	return (os 	<< "'"
				<< b.getName() 
				<< ", sign grade: " 
				<< b.getSignGrade() 
				<< ", execution grade: " 
				<< b.getExecGrade())
				<< ", signed: "
				<< b.isSigned()
				<< "'";
}

