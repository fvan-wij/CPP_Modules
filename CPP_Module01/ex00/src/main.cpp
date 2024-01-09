#include "Zombie.hpp"
#include <iostream>

int main(void)
{
    //Case where we allocate a zombie on the heap;
    Zombie *zom = new Zombie("Zom");
    zom->announce();

        //Same as above, but instead, we use a wrapper function called newZombie(std::string name);
        Zombie* zomboloid;

        zomboloid = newZombie("newZomboloid");
        zomboloid->announce();

    //Case where we use the zombie object temporarily within the function scope
    randomChump("Zomboloid");

    //Case where we allocate on the stack
    Zombie zoomer("Zoomer");
    zoomer.announce();

    delete zom;
    delete zomboloid;
}