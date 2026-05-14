#include "GameOverScreen.h"

#include <QVBoxLayout>
#include <QFont>
#include <QObject>

GameOverScreen::GameOverScreen(int playerScore, int computerScore) : QObject(){
    gameOverPage = new QWidget();

    gameOverPage->setStyleSheet(
        "background-color: rgb(58, 57, 57);"
        );

    QVBoxLayout* layout = new QVBoxLayout(gameOverPage);

    titleLabel = new QLabel("GAME OVER");
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet(
        "font: 700 42pt 'JetBrainsMono Nerd Font Propo';"
        "color: white;"
        );

    playerScoreLabel = new QLabel();
    playerScoreLabel->setAlignment(Qt::AlignCenter);
    playerScoreLabel->setStyleSheet(
        "font: 20pt 'JetBrainsMono Nerd Font Propo';"
        "color: white;"
        );

    computerScoreLabel = new QLabel();
    computerScoreLabel->setAlignment(Qt::AlignCenter);
    computerScoreLabel->setStyleSheet(
        "font: 20pt 'JetBrainsMono Nerd Font Propo';"
        "color: white;"
        );

    winnerLabel = new QLabel();
    winnerLabel->setAlignment(Qt::AlignCenter);
    winnerLabel->setStyleSheet(
        "font: 22pt 'JetBrainsMono Nerd Font Propo';"
        "color: rgb(229, 68, 9);"
        );

    playAgainButton = new QPushButton("Play Again");
    playAgainButton->setFixedWidth(611);
    playAgainButton->setFixedHeight(55);
    playAgainButton->setStyleSheet(
        "font: 18pt 'JetBrainsMono Nerd Font Propo';"
        "color: white;"
        "background-color: rgb(70, 70, 70);"
        );

    layout->addStretch();
    layout->addWidget(titleLabel);
    layout->addSpacing(35);
    layout->addWidget(playerScoreLabel);
    layout->addWidget(computerScoreLabel);
    layout->addSpacing(25);
    layout->addWidget(winnerLabel);
    layout->addSpacing(45);
    layout->addWidget(playAgainButton, 0, Qt::AlignCenter);
    layout->addStretch();

    setScores(playerScore, computerScore);

    QObject::connect(playAgainButton, &QPushButton::clicked, [this]() {
        emit playAgainClicked();
    });
}

QWidget* GameOverScreen::getPage() {
    return gameOverPage;
}

void GameOverScreen::setScores(int playerScore, int computerScore) {
    playerScoreLabel->setText("Player Score: " + QString::number(playerScore));
    computerScoreLabel->setText("Computer Score: " + QString::number(computerScore));

    if (playerScore > computerScore) {
        winnerLabel->setText("Winner: Player");
    }
    else if (computerScore > playerScore) {
        winnerLabel->setText("Winner: Computer");
    }
    else {
        winnerLabel->setText("Result: Draw");
    }
}
