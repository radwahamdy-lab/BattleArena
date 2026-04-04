#include "Archer.h"
#include <iostream>
using namespace std;

Archer::Archer(string n, int h) : Character(n, h){}

Archer::~Archer() {
    if(!isAlive())
        cout << "Archer " << getName() << " has been removed from the game." << endl;
}

int Archer::attack(bool isSpecial) const {
    if(isSpecial){
        int power = getAttackPower() + specialAbility();
        cout << "Archer " << getName() << " has used the special ability: " << ability << " of power " << power << "." << endl;
        return power;
    } else {
        cout << "Archer " << getName() << " has used the base attack power: " << getAttackPower() << "." << endl;
        return getAttackPower();
    }
}

int Archer::specialAbility() const {
    return int(specialPower*getAttackPower());
}

