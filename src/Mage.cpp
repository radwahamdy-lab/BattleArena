<<<<<<< HEAD
#include "Mage.h"
#include <iostream>

Mage::Mage() : Character() {}

void Mage::attack(bool isSpecial) {
	if(isSpecial) {
		scoreInc(3);
    	} else {
        	scoreInc(1);
    	}
}
=======
#include "Mage.h"
#include <iostream>

Mage::Mage()
    : Character()
{}

void Mage::attack(bool isSpecial)
{
    if (isSpecial) {
        scoreInc(3);
    } else {
        scoreInc(1);
    }
}
>>>>>>> e6d812dcbce226c3e20c6aa14237d448526b710d
