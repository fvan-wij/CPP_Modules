#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _NAME("Default"), _SIGN_GRADE(150), _EXEC_GRADE(150)
{
	logDebug(GREEN, "(Default constructor) A Default form has been created. Sign grade: " + std::to_string(_SIGN_GRADE) + ", execution grade: " + std::to_string(_EXEC_GRADE));
}

AForm::AForm(const std::string name, int signGrade, int execGrade) : _NAME(name), _SIGN_GRADE(signGrade), _EXEC_GRADE(execGrade)
{
	if (signGrade > MIN_GRADE || execGrade > MIN_GRADE)
		throw (GradeTooLowException());
	else if (signGrade < MAX_GRADE || execGrade < MAX_GRADE)
		throw (GradeTooHighException());

	this->_bSigned = false;
	logDebug(GREEN, "(Constructor) A new form has been created. Name: " + _NAME + ", sign grade: " + std::to_string(_SIGN_GRADE) + ", execution grade: " + std::to_string(_EXEC_GRADE));
}

AForm::AForm(const AForm& other) : _NAME(other._NAME + " (copy)"), _SIGN_GRADE(other._SIGN_GRADE), _EXEC_GRADE(other._EXEC_GRADE), _bSigned(other._bSigned)
{
	if (other._SIGN_GRADE > MIN_GRADE || other._EXEC_GRADE > MIN_GRADE)
		throw (GradeTooHighException());
	else if (other._SIGN_GRADE < MAX_GRADE || other._EXEC_GRADE < MAX_GRADE)
		throw (GradeTooLowException());
	logDebug(GREEN, "(Copy constructor) A new form has been copied. Name: " + _NAME + ", sign grade: " + std::to_string(_SIGN_GRADE) + ", execution grade: " + std::to_string(_EXEC_GRADE));
}

AForm& AForm::operator=(const AForm& other)
{
	logDebug(GREEN, "(Copy assignment operator) Assigning the signature from " + other._NAME + " to " + this->_NAME);
	this->_bSigned = other._bSigned;
	return (*this);
}

int AForm::getSignGrade() const
{
	return (_SIGN_GRADE);
}

int AForm::getExecGrade() const
{
	return (_EXEC_GRADE);
}

bool AForm::isSigned() const
{
	return (_bSigned);
}

void AForm::beSigned(Bureaucrat& bc)
{
	const int bcGrade = bc.getGrade();

	std::cout << bc << " is attempting to sign " << *this << std::endl;
	if (bcGrade > _SIGN_GRADE)
		throw (GradeTooLowException());
	std::cout << this->getName() << " has been signed by " << bc.getName() << std::endl;
	this->_bSigned = true;
}

std::string AForm::getName() const
{
	return (_NAME);
}

AForm::~AForm()
{
	logDebug(RED, "~(Deconstructor) *SHREDDING NOISE* Form " + _NAME + " has been destroyed");
}

const char* AForm::GradeTooLowException::what() const throw() 
{
	return ("\x1B[33mComputer says NO: Grade is too low\033[0m\t\t");
}

const char* AForm::GradeTooHighException::what() const throw() 
{
	return ("\x1B[33mComputer says NO: Grade is too high\033[0m\t\t");
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return ("\x1B[33mForm is not signed\n\033[0m\t\t");
}

void AForm::logDebug(std::string col, std::string msg)
{
	std::cout << col << msg << "\033[0m\t\t" << std::endl;
}

void AForm::execute(const Bureaucrat& executor) const
{
	if (!this->_bSigned)
		throw (FormNotSignedException());
	else if (executor.getGrade() > _EXEC_GRADE)
		throw (GradeTooLowException());

}

std::ostream& operator<<(std::ostream& os, const AForm& b)
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

