#pragma once

#include <QString>
#include <QTimer>
#include <QStackedWidget>
#include "GameOverScreen.h"

class GameScreen;
enum GameState {MENU, PLAYING, GAMEOVER};

class Game : public QObject{
    Q_OBJECT
    private:
        int playerCharacter;
        int compCharacter;
        GameState currentState; // stores menu, playing, gameover
        int roundTime = 10;
        int remainingTime;
        QTimer* gameTimer;
        GameScreen* gameScreen = nullptr; // stores the actual screen object
        QStackedWidget* stackedWidget;
        GameOverScreen* gameOverScreen = nullptr;
        int playerScore;
        int computerScore;
    public:
        Game(QStackedWidget* stackedwid);
        void start(int player, int computer);
        void updateGame();
        void endGame();
        int getPlayerCharacter();
        int getComputerCharacter();
        int getRemainingTime();
        GameState getGameState();
        GameScreen* getGameScreen();
        void restartGame();
        void quitGame();
        void saveGame();
};
