
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

class GameScreen {
	private:
		QWidget *gamePage = new QWidget;
		int time = 180;
		int obstacles_num = 5;
		Character *player;
		Character *comp;
        Scoreboard* scoreboard;
		vector<Obstacle*> obstacles;
	public:
		GameScreen(QStackedWidget*, int, int);
		QWidget* getPage();

};
