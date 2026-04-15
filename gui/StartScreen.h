#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QStackedWidget>
#include <QObject>

class StartScreen {
	private:
		QWidget *startPage = new QWidget;
	public:
		StartScreen(QStackedWidget* stackedwid, QApplication* a){
			startPage->setStyleSheet("background-color: rgb(58, 57, 57);");
			QVBoxLayout *startLayout = new QVBoxLayout(startPage);

			QLabel *title = new QLabel("Battle Arena");
			title->setGeometry(170, 60, 431, 101);
			title->setStyleSheet("font: 700 36pt 'JetBrainsMono Nerd Font Propo'; color: white");

			QPushButton *newGameBtn = new QPushButton("New Game");
			newGameBtn->setGeometry(90, 190, 611, 51);
			newGameBtn->setStyleSheet("font: 16pt 'DejaVu Sans'; color: white;");

			QPushButton *contGameBtn = new QPushButton("Continue Game");
			contGameBtn->setGeometry(90, 270, 611, 51);
			contGameBtn->setStyleSheet("font: 16pt 'DejaVu Sans'; color: white;");

			QPushButton *exitBtn = new QPushButton("Exit");
			exitBtn->setGeometry(90, 350, 611, 51);
			exitBtn->setStyleSheet("font: 16pt 'DejaVu Sans'; color: white;");

			startLayout->addWidget(title);
			startLayout->addWidget(newGameBtn);
			startLayout->addWidget(contGameBtn);
			startLayout->addWidget(exitBtn);

			QObject::connect(newGameBtn, &QPushButton::clicked, [stackedwid](){
				stackedwid->setCurrentIndex(1);
			});

			QObject::connect(exitBtn, &QPushButton::clicked, a, &QApplication::quit);

		}
		QWidget* getPage(){
			return startPage;
		}
};
