#ifndef GAME_H
#define GAME_H

#include <QString>
#include <QTimer>

class QWidget;
class QStackedWidget;
class GameScreen;
class GameOverScreen;

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

    GameState currentState;

    int remainingTime;

    QTimer* gameTimer;

    GameScreen* gameScreen;
    GameOverScreen* gameOverScreen;

    QStackedWidget* stackedWidget;
    QWidget* characterSelectionPage;

public:
    Game(QString player, QString computer);
    Game(QString player, QString computer, QStackedWidget* stackedwid, QWidget* characterPage);

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
