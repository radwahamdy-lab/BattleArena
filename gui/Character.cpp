#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QPixmap>
#include <QGraphicsScene>
#include <QObject>
#include "Character.h"
#include "Projectile.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Character::Character(QGraphicsScene* sc, int chr, bool isComp) : QObject(), QGraphicsPixmapItem(), scene(sc), character(chr) {
    if(!isComp){
        setFlag(QGraphicsItem::ItemIsFocusable);
        setPos(0,0);
        direction = 1;
    } else {
        setPos(600,0);
        direction = 2;
        QTimer* movement_timer = new QTimer();
        QTimer* shooting_timer = new QTimer();
        movement_timer->start(700);
        shooting_timer->start(1500);
        QObject::connect(movement_timer, &QTimer::timeout, this, &Character::moveRandomly);
        QObject::connect(shooting_timer, &QTimer::timeout, this, [this](){
            shoot();
            QTimer* timer = new QTimer();
            timer->start(160);
            while(timer->remainingTime() > 0){}
            setPixmap(char_ptr[0]);
        });
    }
    if(character == 1) char_ptr = warrior;
    else if(character == 2) char_ptr = archer;
    else if(character == 3) char_ptr = mage;
    setPixmap(char_ptr[0]);
    setZValue(1);
}

void Character::moveRandomly(){
    srand(time(0));

    int random_direction = rand() % 5 + 1;

    int random_time = rand() % 4 + 2;
    QTimer* one_move_timer = new QTimer();
    one_move_timer->setSingleShot(true);
    one_move_timer->start(random_time*100);

    QTimer* small_timer = new QTimer();
    QObject::connect(small_timer, &QTimer::timeout, this, [one_move_timer, random_direction, this](){
        if(one_move_timer->isActive())
            move(random_direction);
    });
    small_timer->start(30);

    QObject::connect(one_move_timer, &QTimer::timeout, this, [this](){
        setPixmap(char_ptr[0]);
        if(direction==1)
            setPixmap(pixmap().transformed(QTransform().scale(1, 1)));
        else if(direction==2)
            setPixmap(pixmap().transformed(QTransform().scale(-1, 1)));
    });

}

void Character::setScore(int s){
    score = s;
    emit scoreChanged();
}

int Character::getScore(){
    return score;
}

int Character::getCharacter(){
    return character;
}

int Character::getDirection(){
    return direction;
}

QPixmap* Character::getPixmaps(){
    if(character==1) return archer;
    if(character==2) return warrior;
    else return mage;
}

void Character::move(int dir){
    setPixmap(char_ptr[1]);
    switch(dir){
        case 1:
            if(x() > 720) return;
            direction = 1;
            moveBy(speed, 0);
            if(collidesWithItem(enemy)) moveBy(-speed, 0);
            break;
        case 2:
            if(x() <= 0) return;
            setPixmap(pixmap().transformed(QTransform().scale(-1, 1)));
            direction = 2;
            moveBy(-speed, 0);
            if(collidesWithItem(enemy)) moveBy(speed, 0);
            break;
        case 3:
            if(y() <= 0) return;
            moveBy(0, -speed);
            if(collidesWithItem(enemy)) moveBy(0, speed);
            break;
        default:
            if(y() > 495) return;
            moveBy(0, speed);
            if(collidesWithItem(enemy)) moveBy(0, -speed);
    }
}

void Character::shoot(){
    setPixmap(char_ptr[2]);
    if(direction==1)
        setPixmap(pixmap().transformed(QTransform().scale(1, 1)));
    else if(direction==2)
        setPixmap(pixmap().transformed(QTransform().scale(-1, 1)));
    Projectile* projectile = new Projectile(scene, enemy, this, 1);
}

void Character::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Space){
        shoot();
    } else {
        if (event->key() == Qt::Key_Left) {
            move(2);
        } else if (event->key() == Qt::Key_Right) {
            move(1);
        } else if (event->key() == Qt::Key_Up){
            move(3);
        } else if (event->key() == Qt::Key_Down){
            move(4);
        }
    }
}

void Character::keyReleaseEvent(QKeyEvent *event) {
    if(event->key() == Qt::Key_Space){
        QTimer* timer = new QTimer();
        timer->start(160);
        while(timer->remainingTime() > 0){}
        setPixmap(char_ptr[0]);
    }

    setPixmap(char_ptr[0]);
    if(direction==1)
        setPixmap(pixmap().transformed(QTransform().scale(1, 1)));
    else if(direction==2)
        setPixmap(pixmap().transformed(QTransform().scale(-1, 1)));
    
}

void Character::setEnemy(QGraphicsItem* en){
    enemy = en;
}
