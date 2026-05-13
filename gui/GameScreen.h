#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QStackedWidget>
#include <QObject>
#include <QTimer>
#include "Character.h"
#include <QGraphicsTextItem>
#include <QString>
#include <functional>

using namespace std;

class GameScreen {
	private:
		QWidget *gamePage = new QWidget;
		int time = 180;
		Character *player;
		Character *comp;
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
