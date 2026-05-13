#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QStackedWidget>
#include <QObject>
#include <QLabel>
#include <QString>
#include <cstdlib>
#include <ctime>

class CharacterScreen {
	private:
		QWidget *characterPage = new QWidget;

		QString userCharacter;
                QString computerCharacter;

	         QString getRandomComputerCharacter() {
		        int choice = rand() % 3 + 1;

      		        if (choice == 1)
           	       		 return "Warrior";
       		        else if (choice == 2)
          	       		 return "Archer";
       		        else
          		         return "Mage";
    }

		void selectCharacter(QString selectedCharacter) {
       	        userCharacter = selectedCharacter;
                computerCharacter = getRandomComputerCharacter();
    }

	public:
		CharacterScreen(QStackedWidget* stackedwid){
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

        		QObject::connect(warriorBtn, &QPushButton::clicked, [this, stackedwid]() {
			    selectCharacter("Warrior");
			    stackedwid->setCurrentIndex(2);
			});

			QObject::connect(archerBtn, &QPushButton::clicked, [this, stackedwid]() {
			    selectCharacter("Archer");
			    stackedwid->setCurrentIndex(2);
			});

			QObject::connect(mageBtn, &QPushButton::clicked, [this, stackedwid]() {
			    selectCharacter("Mage");
			    stackedwid->setCurrentIndex(2);
			});

			QObject::connect(returnBtn, &QPushButton::clicked, [stackedwid](){
				stackedwid->setCurrentIndex(0);
			});

		}
		QWidget* getPage(){
			return characterPage;
		}

		 QString getUserCharacter() {
      		  return userCharacter;
    }

 		 QString getComputerCharacter() {
	          return computerCharacter;
    }
};
