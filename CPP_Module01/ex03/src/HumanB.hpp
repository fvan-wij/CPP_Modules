#pragma once
#include "Weapon.hpp"
#include <string>

class HumanB{
    public:
        HumanB(std::string name, Weapon* weapon);
        ~HumanB();
        void attack(void);

    private:
        Weapon*     _weapon;
        std::string _name;
};
