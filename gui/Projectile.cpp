#include "Projectile.h"
#include <QGraphicsScene>
#include <QRectF>
#include <QPointF>
#include <iostream>
using namespace std;

Projectile::Projectile(QGraphicsScene* sc, QGraphicsItem* tar, Character* src, int inc) : QGraphicsPixmapItem(), scene(sc), target(tar), source(src), scoreInc(inc), character(src->getCharacter()), direction(src->getDirection()) {
    timer = new QTimer(this);

    if(character != 2){
        if(character == 1) setPixmap(arrow);
        else setPixmap(magic);

        // Projectile Position
        QRectF charRect = source->boundingRect();
        QPointF charPos = source->scenePos();
        qreal spawnX = charPos.x() + charRect.width();
        qreal spawnY = charPos.y() + (charRect.height() / 2.0);
        qreal finalY = spawnY - (boundingRect().height() / 2.0);
        setPos(spawnX, finalY);
        
        setZValue(1);
        scene->addItem(this);
        timer->start(16);
        connect(timer, &QTimer::timeout, this, &Projectile::step);
    } else close_attack();
        
}

void Projectile::close_attack() {
    timer->start(160);
    int i=1;
    while(timer->remainingTime() > 0){
        if(isCollide() && !collided) {
            source->setScore(source->getScore() + scoreInc);
            cout << "warrior score increased" << i++ << endl;
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
            setTransformOriginPoint(pixmap().rect().center());
            setRotation(-90);
            moveBy(0, -speed);  
            break;  // Up
        case 3: 
            setPixmap(pixmap().transformed(QTransform().scale(-1, 1)));
            moveBy(-speed, 0);  
            break;  // Left
        default: 
            setTransformOriginPoint(pixmap().rect().center());
            setRotation(90);
            moveBy(0, speed);  
            break;  // Down
    }

    if (isCollide()) {
        timer->stop();
        source->setScore(source->getScore() + scoreInc);
        scene->removeItem(this);
        deleteLater();  // Safe async delete for QObject
    } else if (isOut()) {
        timer->stop();
        scene->removeItem(this);
        deleteLater();
    }
}

bool Projectile::isCollide() {
    QList<QGraphicsItem*> colliding;
    if(character!=2)
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