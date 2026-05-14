#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QStackedWidget>
#include <QObject>
#include <QLabel>
#include <QString>
#include <cstdlib>
#include <ctime>
#include "Game.h"
#include "GameScreen.h"

class CharacterScreen {
	private:

		QWidget *characterPage = new QWidget;

		int userCharacter;
        int computerCharacter;

	    int getRandomComputerCharacter() {
		    int choice = rand() % 3 + 1;
			return choice;
    	}

		void selectCharacter(int selectedCharacter) {
       	    userCharacter = selectedCharacter;
            computerCharacter = getRandomComputerCharacter();
    	}

	public:

		CharacterScreen(QStackedWidget* stackedwid, Game* game){
			srand(time(0));
			characterPage->setStyleSheet("background-color: rgb(58, 57, 57);");
			QVBoxLayout *startLayout = new QVBoxLayout(characterPage);

			QLabel *title = new QLabel("Choose Your Character");
			title->setStyleSheet("font: 700 36pt 'JetBrainsMono Nerd Font Propo'; color: white");

		    QPushButton *warriorBtn = new QPushButton("Warrior");
			warriorBtn->setFixedWidth(611);
			warriorBtn->setFixedHeight(51);
            warriorBtn->setStyleSheet("font: 16pt 'JetBrainsMono Nerd Font Propo'; color: white;");

			QPushButton *archerBtn = new QPushButton("Archer");
			archerBtn->setFixedWidth(611);
			archerBtn->setFixedHeight(51);
            archerBtn->setStyleSheet("font: 16pt 'JetBrainsMono Nerd Font Propo'; color: white;");

			QPushButton *mageBtn = new QPushButton("Mage");
			mageBtn->setFixedWidth(611);
			mageBtn->setFixedHeight(51);
            mageBtn->setStyleSheet("font: 16pt 'JetBrainsMono Nerd Font Propo'; color: white;");

        	QPushButton *returnBtn = new QPushButton("Return");
			returnBtn->setFixedWidth(611);
			returnBtn->setFixedHeight(51);
			returnBtn->setStyleSheet("font: 16pt 'JetBrainsMono Nerd Font Propo'; color: white;");

			startLayout->addWidget(title, 2, Qt::AlignCenter);
		    startLayout->addWidget(warriorBtn, 2, Qt::AlignCenter);
        	startLayout->addWidget(archerBtn, 2, Qt::AlignCenter);
			startLayout->addWidget(mageBtn, 2, Qt::AlignCenter);
			startLayout->addWidget(returnBtn, 2, Qt::AlignCenter);

        	QObject::connect(warriorBtn, &QPushButton::clicked, [this, stackedwid, game]() {
			    selectCharacter(1);
				game->start(userCharacter, computerCharacter);
				stackedwid->addWidget(game->getGameScreen()->getPage());
			    stackedwid->setCurrentIndex(2);
			});

			QObject::connect(archerBtn, &QPushButton::clicked, [this, stackedwid, game]() {
			    selectCharacter(2);
				game->start(userCharacter, computerCharacter);
			    stackedwid->addWidget(game->getGameScreen()->getPage());
				stackedwid->setCurrentIndex(2);
			});

			QObject::connect(mageBtn, &QPushButton::clicked, [this, stackedwid, game]() {
			    selectCharacter(3);
				game->start(userCharacter, computerCharacter);
			    stackedwid->addWidget(game->getGameScreen()->getPage());
				stackedwid->setCurrentIndex(2);
			});

			QObject::connect(returnBtn, &QPushButton::clicked, [stackedwid](){
				stackedwid->setCurrentIndex(0);
			});

		}

		QWidget* getPage(){
			return characterPage;
		}

		int getUserCharacter() {
      		return userCharacter;
    	}

 		int getComputerCharacter() {
	        return computerCharacter;
    	}
};
