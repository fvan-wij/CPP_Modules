#include "Harl.hpp"
#include <iostream>

// Harl::Harl() : _pmf{&Harl::debug, &Harl::info, &Harl::warning, &Harl::error}{
// 	
// }

Harl::Harl() {
		_lvlFn[0]._pmf = &Harl::debug;
		_lvlFn[0].level = "DEBUG";

		_lvlFn[1]._pmf = &Harl::info;
		_lvlFn[1].level = "INFO";

		_lvlFn[2]._pmf = &Harl::warning;
		_lvlFn[2].level = "WARNING";

		_lvlFn[3]._pmf = &Harl::error;
		_lvlFn[3].level = "ERROR";
}
Harl::~Harl(){

}

void	Harl::complain(std::string level){
	for (size_t i = 0; i < 4; i++){
		if (_lvlFn[i].level == level){
			(this->*(_lvlFn[i]._pmf))();
		}
	}
}

void	Harl::debug(void){
	std::cout << "[DEBUG]" << std::endl;
	std::cout << 
"I love having extra bacon for my \
7XL-double-cheese-triple-pickle-specialketchup burger. \
I really do!" << std::endl;
}
void	Harl::info(void){
	std::cout << "[INFO]" << std::endl;
	std::cout << 
"I cannot believe adding extra bacon costs more money.\
You didn’t put enough bacon in my burger! \
If you did, I wouldn’t be asking for more!" << std::endl;
}
void	Harl::warning(void){
	std::cout << "[WARNING]" << std::endl;
	std::cout << 
"I think I deserve to have some extra bacon for free. \
I’ve been coming for years whereas \
you started working here since last month." << std::endl;
}
void	Harl::error(void){
	std::cout << "[ERROR]" << std::endl;
	std::cout << 
"This is unacceptable! I want to speak to the manager now." << std::endl;
}
