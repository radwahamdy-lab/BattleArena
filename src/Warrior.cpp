#include "Warrior.h"
#include <iostream>

Warrior::Warrior()
    : Character()
{}

void Warrior::attack(bool isSpecial)
{
    if (isSpecial) {
        scoreInc(3);
    } else {
        scoreInc(1);
    }
}
