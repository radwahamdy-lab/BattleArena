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

			QVBoxLayout *startLayout = new QVBoxLayout(characterPage);
			QLabel *title = new QLabel("Choose Your Character");
			startLayout->addWidget(title);

		        QPushButton *warriorBtn = new QPushButton("Warrior");
       		        QPushButton *archerBtn = new QPushButton("Archer");
		        QPushButton *mageBtn = new QPushButton("Mage");

        		QPushButton *returnBtn = new QPushButton("Return");
			returnBtn->setGeometry(90, 190, 611, 51);
			returnBtn->setStyleSheet("font: 16pt 'JetBrainsMono Nerd Font Propo'; color: white; background-color: rgb(47, 47, 47);");

			startLayout->addWidget(warriorBtn);
		        startLayout->addWidget(archerBtn);
        		startLayout->addWidget(mageBtn);
			startLayout->addWidget(returnBtn);

        		QObject::connect(warriorBtn, &QPushButton::clicked, [this]() {
			    selectCharacter("Warrior");
			});

			QObject::connect(archerBtn, &QPushButton::clicked, [this]() {
			    selectCharacter("Archer");
			});

			QObject::connect(mageBtn, &QPushButton::clicked, [this]() {
			    selectCharacter("Mage");
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
