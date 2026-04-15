#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QStackedWidget>
#include <QObject>

class CharacterScreen {
	private:
		QWidget *characterPage = new QWidget;
	public:
		CharacterScreen(QStackedWidget* stackedwid){
			QVBoxLayout *startLayout = new QVBoxLayout(characterPage);

			QPushButton *returnBtn = new QPushButton("Return");

			startLayout->addWidget(returnBtn);

			QObject::connect(returnBtn, &QPushButton::clicked, [stackedwid](){
				stackedwid->setCurrentIndex(0);
			});

		}
		QWidget* getPage(){
			return characterPage;
		}
};
