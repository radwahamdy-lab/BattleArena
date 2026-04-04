#include "Mage.h"
#include <iostream>
using namespace std;

Mage::Mage(string n, int h) : Character(n, h) {}

Mage::~Mage() {
    if(!isAlive())
        cout << "Mage " << getName() << " has been removed from the game." << endl;
}

int Mage::attack(bool isSpecial) const {
    if(isSpecial){
        int power = getAttackPower() + specialAbility();
        cout << "Mage " << getName() << " has used the special ability: " << ability << " of power " << power << "." << endl;
        return power;
    } else {
        cout << "Mage " << getName() << " has used the base attack power: " << getAttackPower() << "." << endl;
        return getAttackPower();
    }
}

int Mage::specialAbility() const {
    return int(specialPower*getAttackPower());
}
