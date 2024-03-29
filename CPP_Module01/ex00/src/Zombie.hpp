#pragma once
#include <string>

class Zombie {
    public:
        Zombie(std::string name);
        ~Zombie();
        void    announce (void);

    private:
        std::string _name;
};

void    randomChump(std::string name);
Zombie* newZombie(std::string name);