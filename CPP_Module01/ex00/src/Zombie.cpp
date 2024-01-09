#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name){
    _name = name;
}

Zombie::~Zombie(){
    std::cout << _name << " is sent to the graveyard" << std::endl;
}

void    Zombie::announce (void){
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}