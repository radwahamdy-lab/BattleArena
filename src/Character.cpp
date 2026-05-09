#include "Character.h"

int Character::characterCount = 0;

Character::Character(int s, int spd)
    : score(newScore)
    , speed(newSpeed)
{
    setRect(0, 0, 100, 100);
    setPos(100, 100);
    setBrush(Qt::white);
    setFlag(QGraphicsItem::ItemIsFocusable);

    characterCount++;
}

Character::~Character()
{
    characterCount--;
}

void Character::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left)
        moveBy(-speed, 0);
    else if (event->key() == Qt::Key_Right)
        moveBy(speed, 0);
    else if (event->key() == Qt::Key_Up)
        moveBy(0, -speed);
    else if (event->key() == Qt::Key_Down)
        moveBy(0, speed);
}

void Character::scoreInc(int amount)
{
    score += amount;
}
