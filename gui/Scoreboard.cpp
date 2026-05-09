#include "Scoreboard.h"

Scoreboard::Scoreboard(QGraphicsScene* scene, Character* player, Character* enemy)
{
    this->player = player;
    this->enemy = enemy;

    playerScoreText = new QGraphicsTextItem();
    enemyScoreText = new QGraphicsTextItem();

    QFont font("Arial", 18, QFont::Bold);

    playerScoreText->setFont(font);
    enemyScoreText->setFont(font);

    playerScoreText->setDefaultTextColor(Qt::white);
    enemyScoreText->setDefaultTextColor(Qt::white);

    playerScoreText->setPos(20, 20);
    enemyScoreText->setPos(550, 20);

    scene->addItem(playerScoreText);
    scene->addItem(enemyScoreText);

    updateScores();
}

void Scoreboard::updateScores()
{
    playerScoreText->setPlainText("Player Score: " + QString::number(player->getScore()));
    enemyScoreText->setPlainText("Enemy Score: " + QString::number(enemy->getScore()));
}
