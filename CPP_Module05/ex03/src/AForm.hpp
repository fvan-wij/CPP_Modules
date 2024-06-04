#pragma once
#include <string>

#define MIN_GRADE 150
#define MAX_GRADE 1
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"

class Bureaucrat;

class AForm {
public:
	AForm();
	AForm(const std::string name, int signGrade, int execGrade);
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);
	virtual ~AForm() = 0;

	std::string			getName() const;
	int					getSignGrade() const;
	int					getExecGrade() const;
	bool				isSigned() const;
	void				beSigned(Bureaucrat& bc);
	void				logDebug(std::string col, std::string msg);
	virtual void 		execute(const Bureaucrat& executor) const;

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char*	what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char*	what() const throw();
	};

	class FormNotSignedException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

private:
	 const std::string	_NAME;
	 const int			_SIGN_GRADE;
	 const int			_EXEC_GRADE;
	 bool				_bSigned;
};

std::ostream& operator<<(std::ostream& os, const AForm& b);
