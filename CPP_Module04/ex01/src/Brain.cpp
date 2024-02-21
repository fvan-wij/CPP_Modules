#include "Brain.hpp"

Brain::Brain() {
	Brain::PrintDebugInfo(YELLOW, "Brain constructor called!");
	for (size_t i = 0; i < MEMORY_CAP; i++) {
		_ideas[i] = "Empty idea";
	}
}

Brain::Brain(const Brain& other) {
	Brain::PrintDebugInfo(YELLOW, "Brain copy constructor called!");
	for (size_t i = 0; i < MEMORY_CAP; i++) {
		_ideas[i] = other._ideas[i];
	}
}

Brain& Brain::operator=(const Brain& other) {
	Brain::PrintDebugInfo(YELLOW, "Brain copy assignment called!");
	if (&other == this) {
		return (*this);
	} else {
		for (size_t i = 0; i < MEMORY_CAP; i++) {
			_ideas[i] = other._ideas[i];
		}
		return (*this);
	}
}

Brain::~Brain() {
	Brain::PrintDebugInfo(RED, "~Brain deconstructor called!");

}

void	Brain::PrintDebugInfo(std::string col, std::string msg) {
	std::cout << col << msg << "\033[0m\t\t" << std::endl;
}

void		Brain::setIdea(int index, std::string idea) {
	if (idea.length() == 0) {
		std::cerr << "Error: setIdea argument 'idea' is empty" << std::endl;
		return ;
	} else if (index < 0 || index > MEMORY_CAP) {
		std::cerr << "Error: setIdea argument 'index' must be a number between 0 and 100" << std::endl;
		return ;
	} else {
		_ideas[index] = idea;
	}
}

std::string	Brain::getIdea(int index) {
	if (index < 0 || index > MEMORY_CAP) {
		std::cerr << "Error: getIdea argument 'index' must be a number between 0 and 100" << std::endl;
		return nullptr;
	} else {
		return (_ideas[index]);
	}
}
