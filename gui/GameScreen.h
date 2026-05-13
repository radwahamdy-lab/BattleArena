#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QStackedWidget>
#include <QObject>
#include <QTimer>
#include <QGraphicsTextItem>
#include <QString>

#include <functional>
#include <vector>

#include "Character.h"
#include "Scoreboard.h"
#include "Obstacle.h"

using namespace std;

class GameScreen {

private:
    QWidget *gamePage = new QWidget;
    int time = 180;
    int obstacles_num = 5;
    Character *player;
    Character *comp;
    Scoreboard* scoreboard;
    vector<Obstacle*> obstacles;
    QGraphicsTextItem* timerText;
    function<void()> quitCallback;

public:
    GameScreen(QStackedWidget*, int, int);
    QWidget* getPage();
    void updateTimer(QString text);
    void setQuitCallback(function<void()> callback);
    Character* getPlayer();
    Character* getComp();
};

#endif