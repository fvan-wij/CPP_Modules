#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon& weapon) : _weapon(weapon){
    _name = name;
}

HumanA::~HumanA(){
    std::cout << _name << " leaves the fight" << std::endl;
}

void HumanA::attack(void){
    std::cout << "Microsoft fan " << "attacks with their " << _weapon.getType() << std::endl;
}