#include "Zombie.hpp"
#include <iostream>

int main(void)
{
    Zombie *horde = zombieHorde(5, "Zombo");

    for (size_t i = 0; i < 5; i++)
    {
        horde[i].announce();
        //Alternative way to deconstruct the object
        // horde[i].~Zombie();
    }

    delete [] horde;
}