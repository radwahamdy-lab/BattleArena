#ifndef CHARACTER_H
#define CHARACTER_H

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <string>
using namespace std;

class Character{
	private:
		static int characterCount;
		const string name; // I made it constant because it shouldn't change
		const int attackPower = 5; // I made it constant because it shouldn't change
		int health;

	protected:
		void keyPressEvent(QKeyEvent* event);
		int getAttackPower() const;
	public:
		Character(string n, int h);
		virtual ~Character();
		string getName() const;
		virtual int attack(bool isSpecial) const = 0;
		virtual int specialAbility() const = 0;
		void takeDamage(int damage);
		bool isAlive() const;
		static int getCharacterCount();
		int getHealth() const; // I moved it from protected to public to be able to access it when creating the final scoreboard

};

#endif
