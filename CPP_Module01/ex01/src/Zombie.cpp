#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(){

}

Zombie::Zombie(std::string name){
    _name = name;
}

Zombie::~Zombie(){
    std::cout << "*gets his head blown off by a sawed-off shotgun*" << std::endl;
}

void Zombie::setName (std::string name){
    _name = name;
}

void Zombie::announce(void){
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}