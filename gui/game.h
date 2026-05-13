#ifndef GAME_H
#define GAME_H

#include <QString>
#include <QTimer>

class GameScreen;

enum GameState {
    MENU,
    PLAYING,
    GAMEOVER
};

enum CharacterType {
    ARCHER = 1,
    WARRIOR = 2,
    MAGE = 3
};

class Game {
private:
    QString playerCharacter;
    QString computerCharacter;

    GameState currentState; // stores menu, playing, gameover

    int remainingTime;

    QTimer* gameTimer;

    GameScreen* gameScreen; // stores the actual screen object

public:
    Game(QString player, QString computer);

    void startGame();

    void updateGame();

    void endGame();
    void quitGame();
    void saveGame();

    int playerScore;
    int computerScore;

    QString getPlayerCharacter();
    QString getComputerCharacter();

    int getRemainingTime();

    GameState getGameState();

    GameScreen* getGameScreen();
};

#endif