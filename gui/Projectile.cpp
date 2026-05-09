#include "Projectile.h"
#include <QGraphicsScene>

Projectile::Projectile(QGraphicsScene* sc, QGraphicsItem* tar, Character* src, int inc) : QGraphicsPixmapItem(), scene(sc), target(tar), source(src), scoreInc(inc), character(src->getCharacter()), direction(src->getDirection()) {
    timer = new QTimer(this);

    if(character != WARRIOR){
        setPos(source->x(), source->y());
        if(character == ARCHER) setPixmap(arrow);
        else setPixmap(magic);
        setZValue(1);
        scene->addItem(this);
        timer->start(16);
        connect(timer, &QTimer::timeout, this, &Projectile::step);
    } else 
        close_attack();
        
}

void Projectile::close_attack() {
    source->setPixmap(source->getPixmaps()[2]);
    source->setPixmap(source->getPixmaps()[3]);
    timer->start(16);
    while(timer->remainingTime() > 0){
        if(isCollide()) source->setScore(source->getScore() + scoreInc);
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
        colliding = src->collidingItems();

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