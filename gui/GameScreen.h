#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QStackedWidget>
#include <QObject>
#include <QTimer>
#include "Character.h"

class GameScreen {
	private:
		QWidget *gamePage = new QWidget;
		int time = 180;
		Character *player;
		Character *comp;
	public:
		GameScreen(QStackedWidget*, int, int);
		QWidget* getPage();

};
