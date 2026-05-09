#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QStackedWidget>
#include <QObject>

class StartScreen {
	private:
		QWidget *startPage = new QWidget;
	public:
		StartScreen(QStackedWidget* stackedwid, QApplication* a);
		QWidget* getPage();
};
