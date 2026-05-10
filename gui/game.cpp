#include "game.h"
#include "GameScreen.h"

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