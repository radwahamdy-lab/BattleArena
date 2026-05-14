#pragma once
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QStackedWidget>
#include <QObject>
#include <QTimer>
#include "Character.h"
#include "Scoreboard.h"
#include "Obstacle.h"

#include <vector>
using namespace std;

class GameScreen : public QObject{
    Q_OBJECT
	private:
		QWidget *gamePage = new QWidget;
		int time = 180;
		int obstacles_num = 5;
		Character *player;
		Character *comp;
        Scoreboard* scoreboard;
		vector<Obstacle*> obstacles;
        QGraphicsTextItem *timerText;
        QGraphicsScene *scene;
        QGraphicsView *view;
        QPushButton* quitButton;
	public:
		GameScreen(QStackedWidget*);
		QWidget* getPage();
        void updateTimer(QString text);
        Character* getPlayer();
        Character* getComp();
        void startGame(int, int);

    signals:
        void quitButtonClicked();

};
