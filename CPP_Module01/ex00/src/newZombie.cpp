#include "Zombie.hpp"

Zombie* newZombie(std::string name){
    Zombie *newZomboloid = new Zombie(name);
    return (newZomboloid);
}