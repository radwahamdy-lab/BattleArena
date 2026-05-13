#include "Projectile.h"
#include <QGraphicsScene>
#include <QRectF>
#include <QPointF>
#include <iostream>
using namespace std;

Projectile::Projectile(QGraphicsScene* sc, QGraphicsItem* tar, Character* src, int inc) : QGraphicsPixmapItem(), scene(sc), target(tar), source(src), scoreInc(inc), character(src->getCharacter()), direction(src->getDirection()) {
    timer = new QTimer(this);

    if(character != 1){
        if(character == 2) setPixmap(arrow);
        else setPixmap(magic);

        // Projectile Position
        QRectF charRect = source->boundingRect();
        QPointF charPos = source->scenePos();
        qreal spawnX;
        if(direction==1)
            spawnX = charPos.x() + charRect.width();
        else
            spawnX = charPos.x();
        qreal spawnY = charPos.y() + (charRect.height() / 2.0);
        qreal finalY = spawnY - (boundingRect().height() / 2.0);
        setPos(spawnX, finalY);
        
        setZValue(1);
        scene->addItem(this);
        timer->start(16);
        connect(timer, &QTimer::timeout, this, &Projectile::step);
    } else{
        close_attack();
        collided = false;
    }
        
}

void Projectile::close_attack() {
    timer->start(160);
    while(timer->remainingTime() > 0){
        if(isCollide() && !collided) {
            source->setScore(source->getScore() + scoreInc); 
            collided = true;
        }
    }
}

void Projectile::step() {

    switch (direction) {
        case 1: 
            setPixmap(pixmap().transformed(QTransform().scale(1, 1)));
            moveBy(speed, 0);   
            break;  // Right
        case 2: 
            setPixmap(pixmap().transformed(QTransform().scale(-1, 1)));
            moveBy(-speed, 0);  
            break;  // Left
    }

    if (isCollide()) {
        timer->stop();
        source->setScore(source->getScore() + scoreInc);
        scene->removeItem(this);
        deleteLater();
    } else if (isOut() || collideObstacle()) {
        timer->stop();
        scene->removeItem(this);
        deleteLater();
    }
}

bool Projectile::isCollide() {
    QList<QGraphicsItem*> colliding;
    if(character!=1)
        colliding = collidingItems();
    else
        colliding = source->collidingItems();

    for (QGraphicsItem* item : colliding) {
        if (item == target) return true;
    }
    return false;
}

bool Projectile::isOut() {
    // Check if the projectile has left the scene bounds
    if (!scene) return true;
    return !scene->sceneRect().intersects(boundingRect().translated(pos()));
}

bool Projectile::collideObstacle(){
    bool collides = false;
    for(int i=0; i<source->obstacles.size() && !collides; i++){
        if(collidesWithItem(source->obstacles[i])) {
            collides=true;
        }
    }
    return collides;
}
