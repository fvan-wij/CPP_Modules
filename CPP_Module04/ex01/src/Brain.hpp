#pragma once

#include <iostream>

#define MEMORY_CAP 100
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"

class Brain {
	public:
		Brain();
		Brain(const Brain& other);
		Brain& operator=(const Brain& other);
		~Brain();

		void		PrintDebugInfo(std::string col, std::string msg);
		void		setIdea(int index, std::string idea);
		std::string	getIdea(int index);

	protected:
		std::string _ideas[100];
};
