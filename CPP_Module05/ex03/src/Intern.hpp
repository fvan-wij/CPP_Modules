#pragma once
#include <iostream>
#include "AForm.hpp"
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"

class Intern
{
	public:
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();

		AForm*	makeForm(std::string name, std::string target);
		void	logDebug(std::string col, std::string msg);
		class FormDoesNotExistException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};
