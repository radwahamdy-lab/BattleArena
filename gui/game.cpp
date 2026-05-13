#include "game.h"

#include "GameScreen.h"
#include "GameOverScreen.h"

#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QApplication>
#include <QDir>
#include <QDebug>
#include <QStackedWidget>
#include <QWidget>

Game::Game(QString player, QString computer) {
    playerCharacter = player;
    computerCharacter = computer;

    currentState = PLAYING;

    remainingTime = 180;

    gameTimer = new QTimer();

    gameScreen = nullptr;
    gameOverScreen = nullptr;

    stackedWidget = nullptr;
    characterSelectionPage = nullptr;

    playerScore = 0;
    computerScore = 0;
}

Game::Game(QString player, QString computer, QStackedWidget* stackedwid, QWidget* characterPage) {
    playerCharacter = player;
    computerCharacter = computer;

    currentState = PLAYING;

    remainingTime = 180;

    gameTimer = new QTimer();

    gameScreen = nullptr;
    gameOverScreen = nullptr;

    stackedWidget = stackedwid;
    characterSelectionPage = characterPage;

    playerScore = 0;
    computerScore = 0;
}

void Game::startGame() {
    int playerType = 2;
    int computerType = 2;

    qDebug() << "PLAYER STRING =" << playerCharacter;
    qDebug() << "COMPUTER STRING =" << computerCharacter;

    if (playerCharacter == "Warrior") {
        playerType = 2;
    }
    else if (playerCharacter == "Archer") {
        playerType = 1;
    }
    else if (playerCharacter == "Mage") {
        playerType = 3;
    }

    if (computerCharacter == "Warrior") {
        computerType = 2;
    }
    else if (computerCharacter == "Archer") {
        computerType = 1;
    }
    else if (computerCharacter == "Mage") {
        computerType = 3;
    }

    qDebug() << "PLAYER TYPE =" << playerType;
    qDebug() << "COMPUTER TYPE =" << computerType;

    gameScreen = new GameScreen(
        nullptr,
        playerType,
        computerType
        );

    gameScreen->setQuitCallback([this]() {
        quitGame();
    });

    qDebug() << "SETTING QUIT CALLBACK";

    QObject::connect(gameTimer, &QTimer::timeout, [this]() {
        updateGame();
    });

    gameTimer->start(1000);
}

void Game::updateGame() {
    if (remainingTime > 0) {
        remainingTime--;

        int minutes = remainingTime / 60;
        int seconds = remainingTime % 60;

        QString timeText =
            QString::number(minutes) + ":" +
            QString("%1").arg(seconds, 2, 10, QChar('0'));

        if (gameScreen) {
            gameScreen->updateTimer(timeText);
        }
    }
    else {
        endGame();
    }
}

void Game::endGame() {
    if (currentState == GAMEOVER) {
        return;
    }

    currentState = GAMEOVER;

    if (gameTimer) {
        gameTimer->stop();
    }

    if (gameScreen) {
        gameScreen->updateTimer("GAME OVER");

        if (gameScreen->getPlayer()) {
            playerScore = gameScreen->getPlayer()->getScore();
        }

        if (gameScreen->getComp()) {
            computerScore = gameScreen->getComp()->getScore();
        }
    }

    gameOverScreen = new GameOverScreen(playerScore, computerScore);

    gameOverScreen->setPlayAgainCallback([this]() {
        if (stackedWidget && characterSelectionPage) {
            stackedWidget->setCurrentWidget(characterSelectionPage);
        }
    });

    if (stackedWidget) {
        stackedWidget->addWidget(gameOverScreen->getPage());
        stackedWidget->setCurrentWidget(gameOverScreen->getPage());
    }
}

QString Game::getPlayerCharacter() {
    return playerCharacter;
}

QString Game::getComputerCharacter() {
    return computerCharacter;
}

int Game::getRemainingTime() {
    return remainingTime;
}

GameState Game::getGameState() {
    return currentState;
}

GameScreen* Game::getGameScreen() {
    return gameScreen;
}

void Game::quitGame() {
    QMessageBox::StandardButton reply;

    reply = QMessageBox::question(
        nullptr,
        "Quit Game",
        "Do you want to save before quitting?",
        QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel
        );

    if (reply == QMessageBox::Yes) {
        saveGame();
        QApplication::quit();
    }
    else if (reply == QMessageBox::No) {
        QApplication::quit();
    }

    qDebug() << "QUIT GAME FUNCTION RUNNING";
}

void Game::saveGame() {
    QFile file(QDir::homePath() + "/Desktop/savegame.txt");

    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);

        out << "=== GAME SAVE ===\n";

        out << "Player Character: "
            << playerCharacter << "\n";

        out << "Computer Character: "
            << computerCharacter << "\n";

        out << "Time Remaining: "
            << remainingTime << "\n";

        if (gameScreen && gameScreen->getPlayer()) {
            out << "Player Score: "
                << gameScreen->getPlayer()->getScore() << "\n";
        }

        if (gameScreen && gameScreen->getComp()) {
            out << "Computer Score: "
                << gameScreen->getComp()->getScore() << "\n";
        }

        file.close();
    }
}
