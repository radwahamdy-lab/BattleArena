#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "Character.h"

int main(int argc, char* argv[]){
	QApplication app(argc, argv);
	QGraphicsScene scene;
	scene.setSceneRect(0, 0, 800, 600);

	Character* character = new Character();
	scene.addItem(character);

	QGraphicsView view(&scene);
	view.setFixedSize(800, 600);
	view.setWindowTitle("Battle Arena");
	view.show();

	return app.exec();
}
