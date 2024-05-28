#pragma once
#include <string>
#include <cstdint>

class Bureaucrat {
public:
	Bureaucrat();
	Bureaucrat(Bureaucrat &&);
	Bureaucrat(const Bureaucrat &);
	Bureaucrat &operator=(Bureaucrat &&);
	Bureaucrat &operator=(const Bureaucrat &);
	~Bureaucrat();

private:
	 const std::string	_NAME;
	 uint8_t			_grade;
};

