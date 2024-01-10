#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

#define NO_WEAPON

int main(void)
{
    //HumanA does have a weapon
    Weapon xboxController = Weapon("Xbox 360 controller");

    HumanA msFan("Microsoft fanboy", xboxController);
    msFan.attack();
    xboxController.setType("Xbox One controller");
    msFan.attack();

    #ifndef NO_WEAPON
        HumanB sonyFan("Sony fanboy", NULL);
        sonyFan.attack();
        sonyFan.attack();
    #endif

    #ifdef NO_WEAPON
        Weapon psController = Weapon("Playstation 4 controller");

        HumanB sonyFan("Sony fanboy", &psController);
        sonyFan.attack();
        psController.setType("Playstation 5 controller");
        sonyFan.attack();
    #endif

    return EXIT_SUCCESS;
}