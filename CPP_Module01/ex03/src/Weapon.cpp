#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(std::string weapon){
    _type = weapon;
}

Weapon::~Weapon(){
    std::cout << _type << " gets dropped on the floor" << std::endl;
}

std::string& Weapon::getType(void){
    return (_type);
}

void Weapon::setType(std::string newType){
    _type = newType;
}