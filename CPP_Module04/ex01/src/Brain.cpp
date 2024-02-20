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
	if (index >= 0 && index < 100) {
		_ideas[index] = idea;
	}
}
