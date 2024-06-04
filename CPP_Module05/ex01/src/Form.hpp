#pragma once
#include <string>

#define MIN_GRADE 150
#define MAX_GRADE 1

class Bureaucrat;

class Form {
public:
	Form();
	Form(const std::string name, int signGrade, int execGrade);
	Form(const Form &other);
	Form &operator=(const Form &other);
	~Form();

	std::string			getName() const;
	int					getSignGrade() const;
	int					getExecGrade() const;
	bool				isSigned() const;
	void				beSigned(Bureaucrat& bc);
	void				logDebug(std::string col, std::string msg);

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

private:
	 const std::string	_NAME;
	 const int			_SIGN_GRADE;
	 const int			_EXEC_GRADE;
	 bool				_bSigned;
};

std::ostream& operator<<(std::ostream& os, const Form& b);

