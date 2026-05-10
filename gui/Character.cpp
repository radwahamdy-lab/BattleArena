#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QPixmap>
#include <QGraphicsScene>
#include <QObject>
#include "Character.h"
#include "Projectile.h"

#include <iostream>
using namespace std;

Character::Character(QGraphicsScene* sc, int chr, bool isComp) : QObject(), QGraphicsPixmapItem(), scene(sc), character(chr) {
    if(!isComp){
        setFlag(QGraphicsItem::ItemIsFocusable);
        setPos(0,0);
        direction = 1;
    } else {
        setPos(600,0);
        direction = 3;
    }
    if(character == 1) char_ptr = archer;
    else if(character == 2) char_ptr = warrior;
    else if(character == 3) char_ptr = mage;
    setPixmap(char_ptr[0]);
    setZValue(1);
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

void Character::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Space){
        setPixmap(char_ptr[2]);
        if(direction==1) {
            setPixmap(pixmap().transformed(QTransform().scale(1, 1)));
            setTransformOriginPoint(pixmap().rect().center());
            setRotation(0);
        } else if(direction==2){
            setPixmap(pixmap().transformed(QTransform().scale(1, 1)));
            setTransformOriginPoint(pixmap().rect().center());
            setRotation(-90);
        } else if(direction==3){
            setPixmap(pixmap().transformed(QTransform().scale(-1, 1)));
            setTransformOriginPoint(pixmap().rect().center());
            setRotation(0);
        } else {
            setPixmap(pixmap().transformed(QTransform().scale(1, 1)));
            setTransformOriginPoint(pixmap().rect().center());
            setRotation(90);
        }
        Projectile* projectile = new Projectile(scene, enemy, this, 1);
    } else {
        setPixmap(char_ptr[1]);
        if (event->key() == Qt::Key_Left && x() >= 0) {
            setPixmap(pixmap().transformed(QTransform().scale(-1, 1)));
            direction = 3;
            moveBy(-speed, 0);
        } else if (event->key() == Qt::Key_Right && x() <= 720) {
            direction = 1;
            moveBy(speed, 0);
        } else if (event->key() == Qt::Key_Up && y() >= 0) {
            setTransformOriginPoint(pixmap().rect().center());
            setRotation(-90);
            direction = 2;
            moveBy(0, -speed);
        } else if (event->key() == Qt::Key_Down && y() <= 495) {
            setTransformOriginPoint(pixmap().rect().center());
            setRotation(90);
            direction = 4;
            moveBy(0, speed);
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
    if(direction==1) {
        setPixmap(pixmap().transformed(QTransform().scale(1, 1)));
        setTransformOriginPoint(pixmap().rect().center());
        setRotation(0);
    } else if(direction==2){
        setPixmap(pixmap().transformed(QTransform().scale(1, 1)));
        setTransformOriginPoint(pixmap().rect().center());
        setRotation(-90);
    } else if(direction==3){
        setPixmap(pixmap().transformed(QTransform().scale(-1, 1)));
        setTransformOriginPoint(pixmap().rect().center());
        setRotation(0);
    } else {
        setPixmap(pixmap().transformed(QTransform().scale(1, 1)));
        setTransformOriginPoint(pixmap().rect().center());
        setRotation(90);
    }
    
}

void Character::setEnemy(QGraphicsItem* en){
    enemy = en;
}
