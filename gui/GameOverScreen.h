#ifndef GAMEOVERSCREEN_H
#define GAMEOVERSCREEN_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QString>

#include <functional>

class GameOverScreen {
private:
    QWidget* gameOverPage;

    QLabel* titleLabel;
    QLabel* playerScoreLabel;
    QLabel* computerScoreLabel;
    QLabel* winnerLabel;

    QPushButton* playAgainButton;

    std::function<void()> playAgainCallback;

public:
    GameOverScreen(int playerScore, int computerScore);

    QWidget* getPage();

    void setScores(int playerScore, int computerScore);

    void setPlayAgainCallback(std::function<void()> callback);
};

#endif
