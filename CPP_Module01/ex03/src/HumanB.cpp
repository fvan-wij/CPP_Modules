#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name, Weapon* weapon) : _weapon(weapon){
    _name = name;
}

HumanB::~HumanB(){
    std::cout << _name << " leaves the fight" << std::endl;
}

void HumanB::attack(void){
    if (!_weapon)
    {
        std::cout << _name << " attacks with their empty hands" << std::endl;
    }
    else
    {
        std::cout << _name << " attacks with their " << (*_weapon).getType() << std::endl;
    }
}