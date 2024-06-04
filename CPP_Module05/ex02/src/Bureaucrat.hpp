#pragma once

#include <exception>
#include <string>
#include <iostream>

#define MIN_GRADE 150
#define MAX_GRADE 1
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"

class Form;

class Bureaucrat {
public:
	Bureaucrat();
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat();

	std::string			getName() const;
	int					getGrade() const;
	void				setGrade(int grade);
	void				incrementGrade();
	void				decrementGrade();
	void				signForm(Form& form);
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
	 int				_grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);
