#include "GameScreen.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QApplication>
#include <QDir>
#include <QDebug>
#include "game.h"

Game::Game(QString player, QString computer) {
    playerCharacter = player;
    computerCharacter = computer; // constructor into class variables

    currentState = PLAYING;

    remainingTime = 180; // 3 minutes

    gameTimer = new QTimer();

    gameScreen = nullptr;
}

void Game::startGame() {

    int playerType = 2;
    int computerType = 2;

    qDebug() << "PLAYER STRING =" << playerCharacter;
    qDebug() << "COMPUTER STRING =" << computerCharacter;

    // PLAYER MAPPING
    if(playerCharacter == "Warrior"){
        playerType = 2;
    }
    else if(playerCharacter == "Archer"){
        playerType = 1;
    }
    else if(playerCharacter == "Mage"){
        playerType = 3;
    }

    // COMPUTER MAPPING
    if(computerCharacter == "Warrior"){
        computerType = 2;
    }
    else if(computerCharacter == "Archer"){
        computerType = 1;
    }
    else if(computerCharacter == "Mage"){
        computerType = 3;
    }

    qDebug() << "PLAYER TYPE =" << playerType;
    qDebug() << "COMPUTER TYPE =" << computerType;

    gameScreen = new GameScreen(
        nullptr,
        playerType,
        computerType
        );

    gameScreen->setQuitCallback([this](){

        quitGame();
    });

    qDebug() << "SETTING QUIT CALLBACK";

    // when the timer emits a timeout signal,
    // call updateGame() every second
    QObject::connect(gameTimer, &QTimer::timeout, [this]() {
        updateGame();
    });

    gameTimer->start(1000);
}

void Game::updateGame() {

    if (remainingTime > 0) { // is game still running

        remainingTime--;

        int minutes = remainingTime / 60;
        int seconds = remainingTime % 60; // to convert time

        QString timeText =
            QString::number(minutes) + ":" +
            QString("%1").arg(seconds, 2, 10, QChar('0')); // to pad numbers with zeros

        gameScreen->updateTimer(timeText);
    }
    else {
        endGame();
    }
}

void Game::endGame() {

    currentState = GAMEOVER;

    gameTimer->stop();

    gameScreen->updateTimer("GAME OVER");
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

void Game::quitGame(){

    QMessageBox::StandardButton reply;

    reply = QMessageBox::question(
        nullptr,
        "Quit Game",
        "Do you want to save before quitting?",
        QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel
        );

    if(reply == QMessageBox::Yes){

        saveGame();

        QApplication::quit();
    }
    else if(reply == QMessageBox::No){

        QApplication::quit();
    }
    qDebug() << "QUIT GAME FUNCTION RUNNING";
}

void Game::saveGame(){

    QFile file(QDir::homePath() + "/Desktop/savegame.txt");

    if(file.open(QIODevice::WriteOnly | QIODevice::Text)){

        QTextStream out(&file);

        out << "=== GAME SAVE ===\n";

        out << "Player Character: "
            << playerCharacter << "\n";

        out << "Computer Character: "
            << computerCharacter << "\n";

        out << "Time Remaining: "
            << remainingTime << "\n";

        out << "Player Score: "
            << gameScreen->getPlayer()->getScore() << "\n";

        out << "Computer Score: "
            << gameScreen->getComp()->getScore() << "\n";

        file.close();
    }
}