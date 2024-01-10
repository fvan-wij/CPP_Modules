#include "Zombie.hpp"
#include <iostream>

Zombie* zombieHorde( int N, std::string name )
{
    Zombie* horde;

    horde = new Zombie[N];

    //Naive approach, resulted in the zombie being deconstructed once it goes out of the for loop scope
    // for (size_t i = 0; i < (size_t) N; i++)
    // {
    //    horde[i] = Zombie(name);
    //    std::cout << "Deconstructed already!?" << std::endl;
    // }

    for (size_t i = 0; i < (size_t)N; i++)
    {
       horde[i].setName(name);
    }

    return (horde);
}