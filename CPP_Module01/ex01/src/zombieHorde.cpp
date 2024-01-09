#include "Zombie.hpp"

Zombie* zombieHorde( int n, std::string name )
{
    Zombie* horde;

    for (size_t i = 0; i < n; i++)
    {
       horde[i] = Zombie(name);
    }
    return (horde);
}