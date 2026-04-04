#include "Character.h"
#include <iostream>
#include <QKeyEvent>
using namespace std;

int Character::characterCount = 0;

Character::Character(string n, int h) : name(n) {
	health = h;
	setRect(0, 0, 100, 100);
	setPos(100, 100);
	setBrush(Qt::blue);
	setFlag(QGraphicsItem::ItemIsFocusable);
	setFocus();
	characterCount++;
}

Character::~Character() {
	characterCount--;
}

int Character::getAttackPower() const {
	return attackPower;
}

int Character::getHealth() const {
	return health;
}

string Character::getName() const {
	return name;
}

void Character::takeDamage(int damage) {
	if(health - damage <= 0) {
		health = 0;
		cout << name << " has been defeated." << endl;
	} else { 
		health -= damage;
		cout << name << " has " << health << " health remaining." << endl;
	}
}

void Character::keyPressEvent(QKeyEvent *event){
	if(event->key() == Qt::Key_Left)
		moveBy(-10,0);
}


bool Character::isAlive() const {
	if(health > 0) return true;
	else return false;
}

int Character::getCharacterCount() {
	return characterCount;
}

