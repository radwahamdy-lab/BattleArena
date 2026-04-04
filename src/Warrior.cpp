#include "Warrior.h"
#include <iostream>
using namespace std;

Warrior::Warrior(string n, int h) : Character(n, h){}

Warrior::~Warrior() {
    if(!isAlive())
        cout << "Warrior " << getName() << " has been removed from the game." << endl;
}

int Warrior::attack(bool isSpecial) const {
    if(isSpecial){
        int power = getAttackPower() + specialAbility();
        cout << "Warrior " << getName() << " has used the special ability: " << ability << " of power " << power << "." << endl;
        return power;
    } else {
        cout << "Warrior " << getName() << " has used the base attack power: " << getAttackPower() << "." << endl;
        return getAttackPower();
    }
}


int Warrior::specialAbility() const {
    return int(specialPower*getAttackPower());
}

