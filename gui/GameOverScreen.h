#ifndef GAMEOVERSCREEN_H
#define GAMEOVERSCREEN_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QString>

#include <functional>

class GameOverScreen : public QObject {
    Q_OBJECT
private:
    QWidget* gameOverPage;

    QLabel* titleLabel;
    QLabel* playerScoreLabel;
    QLabel* computerScoreLabel;
    QLabel* winnerLabel;

    QPushButton* playAgainButton;

public:
    GameOverScreen(int playerScore, int computerScore);

    QWidget* getPage();

    void setScores(int playerScore, int computerScore);

signals:
    void playAgainClicked();
};

#endif