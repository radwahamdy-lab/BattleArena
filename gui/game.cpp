#include "game.h"
#include "GameScreen.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QApplication>
#include <QDir>

Game::Game(QString player, QString computer) {
    playerCharacter = player;
    computerCharacter = computer; // constructor into class variables

    currentState = PLAYING;

    remainingTime = 180; // 3 minutes

    gameTimer = new QTimer();

    gameScreen = nullptr;
}

void Game::startGame() {

    int playerType;
    int computerType;

    // convert player character string into enum value in game.h
    if(playerCharacter == "Warrior")
        playerType = WARRIOR;
    else if(playerCharacter == "Archer")
        playerType = ARCHER;
    else
        playerType = MAGE;

    // convert computer character string into enum value
    if(computerCharacter == "Warrior")
        computerType = WARRIOR;
    else if(computerCharacter == "Archer")
        computerType = ARCHER;
    else
        computerType = MAGE;


    gameScreen = new GameScreen(
        nullptr,
        playerType,
        computerType
        );

    gameScreen->setQuitCallback([this](){

        quitGame();
    });

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