#include "Archer.h"
#include <iostream>

Archer::Archer()
    : Character()
{}

void Archer::attack(bool isSpecial)
{
    if (isSpecial) {
        scoreInc(3);
    } else {
        scoreInc(1);
    }
}
