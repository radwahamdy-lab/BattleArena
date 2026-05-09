#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QStackedWidget>
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "../include/Warrior.h"

class CharacterScreen {
	private:
		QWidget* characterPage;
	public:
		CharacterScreen(QStackedWidget* stackedwid){};
		QWidget* getPage(){
			return characterPage;
		}
};
