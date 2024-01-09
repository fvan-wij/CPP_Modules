#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name){
    _name = name;
}

Zombie::~Zombie(){

}

void Zombie::announce(void){
    std::cout << _name << "BraiiiiiiinnnzzzZ..." << std::endl;
}