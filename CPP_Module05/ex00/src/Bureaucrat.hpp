#pragma once
#include <exception>
#include <string>
#include <iostream>

#define MIN_GRADE 150
#define MAX_GRADE 1

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
