#ifndef WARRIOR_H
#define WARRIOR_H
#include "Character.h"

class Warrior : public Character {
	public:
        Warrior();
        void attack(bool isSpecial) override;
};
#endif
