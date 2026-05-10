<<<<<<< HEAD
#pragma once
#include <QGraphicsPixmapItem>
#include <QTimer>
#include "Character.h"

class Character;

class Projectile : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT  // Required for QTimer signals/slots

public:
    Projectile(QGraphicsScene* sc, QGraphicsItem* tar, Character* src, int inc);
    

private slots:
    void step();  // Called by timer each tick

private:
    bool isCollide();
    bool isOut();
    void close_attack();

    QPixmap arrow = QPixmap(":characters/Archer/Arrow.png");
    QPixmap magic = QPixmap(":characters/Mage/Magic.png");
    QTimer* timer;
    QGraphicsScene* scene;
    Character* source;
    QGraphicsItem* target;

    int speed = 5;
    int character;
    int direction;
    int scoreInc;

    bool collided = false;
=======
#pragma once
#include <QGraphicsPixmapItem>
#include <QTimer>
#include "Character.h"

class Character;

class Projectile : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT  // Required for QTimer signals/slots

public:
    Projectile(QGraphicsScene* sc, QGraphicsItem* tar, Character* src, int inc);
    void attack();
    void close_attack();

private slots:
    void step();  // Called by timer each tick

private:
    bool isCollide();
    bool isOut();

    QPixmap arrow = QPixmap(":characters/Archer/Arrow.png");
    QPixmap magic = QPixmap(":characters/Mage/Magic.png");
    QTimer* timer;
    QGraphicsScene* scene;
    Character* source;
    QGraphicsItem* target;

    int speed = 5;
    int character;
    int direction;
    int scoreInc;
>>>>>>> e6d812dcbce226c3e20c6aa14237d448526b710d
};