#ifndef WARRIOR_H
#define WARRIOR_H
#include "Character.h"

class Warrior : public Character{
    private:
        const string ability = "Power Strike";
        // If not isSpecial the attackPower will be equal to the base attack power in the Character class
        // else attackPower will be greater than base attack power by (specialPower*100) percent
        const double specialPower = 0.5;
    public:
        // I am passing the healh as 20 by default because I can't initialize the health in Warrior then pass it to Character
        Warrior(string n, int h=20);
        ~Warrior();
        int attack(bool isSpecial) const;
        int specialAbility() const;

};

#endif