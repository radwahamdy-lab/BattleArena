#ifndef MAGE_H
#define MAGE_H
#include "Character.h"

class Mage : public Character{
    private:
        const string ability = "Arcane Storm";
        const double specialPower = 1;
    public:
        Mage(string n, int h=7);
        ~Mage();
        int attack(bool isSpecial) const;
        int specialAbility() const;

};

#endif