#pragma once
#include <string>

class Weapon{
    public:
        Weapon(std::string weapon);
        ~Weapon();
        std::string&    getType(void);
        void            setType(std::string newType);

    private:
        std::string _type;
};