<<<<<<< HEAD
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QStackedWidget>
#include <QObject>
#include <QTimer>
#include "Character.h"
#include "Scoreboard.h"

class GameScreen {
	private:
		QWidget *gamePage = new QWidget;
		int time = 180;
		Character *player;
		Character *comp;
        Scoreboard* scoreboard;
	public:
		GameScreen(QStackedWidget*, int, int);
		QWidget* getPage();

};
=======
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
>>>>>>> e6d812dcbce226c3e20c6aa14237d448526b710d
