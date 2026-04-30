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
