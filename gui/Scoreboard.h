#pragma once

#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <QFont>
#include <QString>
#include "Character.h"

class Scoreboard
{
private:
    QGraphicsTextItem* playerScoreText;
    QGraphicsTextItem* enemyScoreText;

    Character* player;
    Character* enemy;

public:
    Scoreboard(QGraphicsScene* scene, Character* player, Character* enemy);

    void updateScores();
};
