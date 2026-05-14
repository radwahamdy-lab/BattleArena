#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QStackedWidget>
#include <QObject>
#include "Game.h"

class StartScreen {
	private:
		QWidget *startPage = new QWidget;
		Game* game;
	public:
		StartScreen(QStackedWidget* stackedwid, QApplication* a, Game* g);
		QWidget* getPage();
		void continueGame();
};
