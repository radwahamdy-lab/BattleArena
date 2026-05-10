<<<<<<< HEAD
#pragma once
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QPixmap>

class Character : public QGraphicsPixmapItem {
    public:
        Character(QGraphicsScene*, int, bool);
        void setScore(int s);
        int getScore();
        int getCharacter();
        int getDirection();
        QPixmap* getPixmaps();
        void setEnemy(QGraphicsItem*);
    protected:
        void keyPressEvent(QKeyEvent *event);
        void keyReleaseEvent(QKeyEvent *event);

    private:
        QPixmap archer_idle = QPixmap(":characters/Archer/Archer_Idle.png");
        QPixmap archer_run = QPixmap(":characters/Archer/Archer_Run.png");
        QPixmap archer_attack = QPixmap(":characters/Archer/Archer_Attack.png");
        QPixmap warrior_idle = QPixmap(":characters/Warrior/Warrior_Idle.png");
        QPixmap warrior_run = QPixmap(":characters/Warrior/Warrior_Run.png");
        QPixmap warrior_attack = QPixmap(":characters/Warrior/Warrior_Attack2.png");
        QPixmap mage_idle = QPixmap(":characters/Mage/Mage_Idle.png");
        QPixmap mage_run = QPixmap(":characters/Mage/Mage_Run.png");
        QPixmap mage_attack = QPixmap(":characters/Mage/Mage_Attack.png");
        QPixmap archer[3] = {archer_idle, archer_run, archer_attack};
        QPixmap warrior[3] = {warrior_idle, warrior_run, warrior_attack};
        QPixmap mage[3] = {mage_idle, mage_run, mage_attack};
        QPixmap* char_ptr;
        QGraphicsScene* scene;
        QGraphicsItem* enemy;
        int speed = 5;
        int character;
        int direction;
        int score = 0;

};
=======
#pragma once
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QPixmap>

enum CharacterType {
    ARCHER = 1,
    WARRIOR = 2,
    MAGE = 3
};

class Character : public QGraphicsPixmapItem {
    public:
        Character(QGraphicsScene*, int, bool);
        void setScore(int s);
        int getScore();
        int getCharacter();
        int getDirection();
        QPixmap* getPixmaps();
        void setEnemy(QGraphicsItem*);
    protected:
        void keyPressEvent(QKeyEvent *event);
        void keyReleaseEvent(QKeyEvent *event);

    private:
        QPixmap archer_idle = QPixmap(":characters/Archer/Archer_Idle.png");
        QPixmap archer_run = QPixmap(":characters/Archer/Archer_Run.png");
        QPixmap warrior_idle = QPixmap(":characters/Warrior/Warrior_Idle.png");
        QPixmap warrior_run = QPixmap(":characters/Warrior/Warrior_Run.png");
        QPixmap warrior_attack1 = QPixmap(":characters/Warrior/Warrior_Attack.png");
        QPixmap warrior_attack2 = QPixmap(":characters/Warrior/Warrior_Attack2.png");
        QPixmap mage_idle = QPixmap(":characters/Mage/Mage_Idle.png");
        QPixmap mage_run = QPixmap(":characters/Mage/Mage_Run.png");
        QPixmap archer[2] = {archer_idle, archer_run};
        QPixmap warrior[4] = {warrior_idle, warrior_run, warrior_attack1, warrior_attack2};
        QPixmap mage[2] = {mage_idle, mage_run};
        QPixmap* char_ptr;
        QGraphicsScene* scene;
        QGraphicsItem* enemy;
        int speed = 5;
        int character;
        int direction;
        int score = 0;

};
>>>>>>> e6d812dcbce226c3e20c6aa14237d448526b710d
