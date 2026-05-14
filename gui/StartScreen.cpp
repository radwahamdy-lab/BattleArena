#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QStackedWidget>
#include <QObject>
#include <QLabel>
#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QDebug>
#include <iostream> 
#include "StartScreen.h"
#include "GameScreen.h"


using namespace std;


StartScreen::StartScreen(QStackedWidget* stackedwid, QApplication* a, Game* g){
    game = g;
    this->stackedwid = stackedwid;

    startPage->setStyleSheet("background-color: rgb(58, 57, 57);");
    QVBoxLayout *startLayout = new QVBoxLayout(startPage);

    QLabel *title = new QLabel("Battle Arena");
    title->setStyleSheet("font: 700 36pt 'JetBrainsMono Nerd Font Propo'; color: white");

    QPushButton *newGameBtn = new QPushButton("New Game");
    newGameBtn->setFixedWidth(611);
    newGameBtn->setFixedHeight(51);
    newGameBtn->setStyleSheet("font: 16pt 'JetBrainsMono Nerd Font Propo'; color: white;");

    QPushButton *contGameBtn = new QPushButton("Continue Game");
    contGameBtn->setFixedWidth(611);
    contGameBtn->setFixedHeight(51);
    contGameBtn->setStyleSheet("font: 16pt 'JetBrainsMono Nerd Font Propo'; color: white;");

    QPushButton *exitBtn = new QPushButton("Exit");
    exitBtn->setFixedWidth(611);
    exitBtn->setFixedHeight(51);
    exitBtn->setStyleSheet("font: 16pt 'JetBrainsMono Nerd Font Propo'; color: white;");

    startLayout->addWidget(title, 2, Qt::AlignCenter);
    startLayout->addWidget(newGameBtn, 2, Qt::AlignCenter);
    startLayout->addWidget(contGameBtn, 2, Qt::AlignCenter);
    startLayout->addWidget(exitBtn, 2, Qt::AlignCenter);

    QObject::connect(newGameBtn, &QPushButton::clicked, [stackedwid](){
        stackedwid->setCurrentIndex(1);
    });

    QObject::connect(contGameBtn, &QPushButton::clicked, [this](){
        continueGame();
    });

    QObject::connect(exitBtn, &QPushButton::clicked, a, &QApplication::quit);

}

QWidget* StartScreen::getPage(){
    return startPage;
}

void StartScreen::continueGame(){
    QFile file("games/savegame.txt");

    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        // Check if file is empty
        if(file.size() == 0){
            qDebug() << "Save file is empty";
            return;
        }

        QTextStream in(&file);

        int playerCharacter = 0;
        int computerCharacter = 0;
        int timeRemaining = 0;
        int playerScore = 0;
        int computerScore = 0;

        while(!in.atEnd())
        {
            QString line = in.readLine();

            // Skip title line
            if(line.startsWith("==="))
                continue;

            QStringList parts = line.split(":");

            if(parts.size() < 2)
                continue;

            QString key = parts[0].trimmed();
            QString value = parts[1].trimmed();

            if(key == "Player Character")
                playerCharacter = value.toInt();

            else if(key == "Computer Character")
                computerCharacter = value.toInt();

            else if(key == "Time Remaining")
                timeRemaining = value.toInt();

            else if(key == "Player Score")
                playerScore = value.toInt();

            else if(key == "Computer Score")
                computerScore = value.toInt();
        }

        file.close();
        game->start(playerCharacter, computerCharacter);
		stackedwid->addWidget(game->getGameScreen()->getPage());
		stackedwid->setCurrentIndex(2);
    }
    else
    {
        qDebug() << "Could not open save file";
    }
}
