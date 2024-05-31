#pragma once
#include <exception>
#include <string>
#include <iostream>

#define MIN_GRADE 150
#define MAX_GRADE 1

class Form {
public:
	Form();
	Form(const std::string name, int grade);
	Form(const Form &other);
	Form &operator=(const Form &other);
	~Form();

	std::string			getName() const;
	int					getSignGrade() const;
	int					getExecGrade() const;
	// void				setGrade(int grade);
	// void				incrementGrade();
	// void				decrementGrade();

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

