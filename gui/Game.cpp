#include "Game.h"
#include "GameScreen.h"
#include "GameOverScreen.h"
#include <QStackedWidget>
#include <QMessageBox>
#include <QObject>
#include <QApplication>
#include <QFile>
#include <QDir>

Game::Game(QStackedWidget* stackedwid) : QObject(), stackedWidget(stackedwid){
    
}

void Game::start(int player, int computer){
    currentState = PLAYING;
    remainingTime = roundTime;
    playerCharacter = player;
    compCharacter = computer;
    gameTimer = new QTimer();
    if(!gameScreen)
        gameScreen = new GameScreen(stackedWidget);
    gameScreen->startGame(playerCharacter, compCharacter);
    updateGame();
    QObject::connect(gameTimer, &QTimer::timeout, [this](){
        if(currentState == PLAYING)
            updateGame();
    });

    QObject::connect(gameScreen, &GameScreen::quitButtonClicked, [this](){
        quitGame();
    });

    gameTimer->start(1000);
}

void Game::updateGame() {

    if(remainingTime != 0){
        remainingTime--;
        int minutes = this->remainingTime/60;
        int seconds = this->remainingTime%60;
        string seconds_str = to_string(seconds).length()==1 ? "0"+to_string(seconds) : to_string(seconds);
        string time_str = to_string(minutes) + ":" + seconds_str;
        QString time_qt = QString::fromStdString(time_str);
        gameScreen->updateTimer(time_qt);
    } else {
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

    QObject::connect(gameOverScreen, &GameOverScreen::playAgainClicked, this, &Game::restartGame);

    if (stackedWidget) {
        stackedWidget->addWidget(gameOverScreen->getPage());
        stackedWidget->setCurrentWidget(gameOverScreen->getPage());
    }
}

int Game::getPlayerCharacter() {
    return playerCharacter;
}

int Game::getComputerCharacter() {
    return compCharacter;
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

void Game::restartGame(){
    stackedWidget->removeWidget(gameScreen->getPage());
    delete gameScreen;
    gameScreen = new GameScreen(stackedWidget);
    stackedWidget->addWidget(gameScreen->getPage());
    stackedWidget->setCurrentIndex(0);
    stackedWidget->removeWidget(gameOverScreen->getPage());
    currentState = MENU;
}


void Game::quitGame() {
    currentState = MENU;
    gameScreen->getComp()->getMovementTimer()->stop();
    gameScreen->getComp()->getShootingTimer()->stop();
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
    } else if(reply == QMessageBox::Cancel){
        currentState = PLAYING;
        gameScreen->getComp()->continueTimers();
    }

    qDebug() << "QUIT GAME FUNCTION RUNNING";
}

void Game::saveGame() {
    QFile file("games/savegame.txt");

    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);

        out << "=== GAME SAVE ===\n";

        out << "Player Character: "
            << playerCharacter << "\n";

        out << "Computer Character: "
            << compCharacter << "\n";

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