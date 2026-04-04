#ifndef ARCHER_H
#define ARCHER_H
#include "Character.h"

class Archer : public Character{
    private:
        const string ability = "Double Shot";
        const double specialPower = 0.5;
    public:
        Archer(string n, int h=10);
        ~Archer();
        int attack(bool isSpecial) const;
        int specialAbility() const;

};

#endif