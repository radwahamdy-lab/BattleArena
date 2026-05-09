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

class GameScreen {
	private:
		QWidget *gamePage = new QWidget;
		int time = 180;
		Character *player;
		Character *comp;
        QGraphicsTextItem* timerText;
	public:
		GameScreen(QStackedWidget*, int, int);
		QWidget* getPage();
        void updateTimer(QString text);

};

#endif
