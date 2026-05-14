#include <QApplication>
#include <QStackedWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QMainWindow>
#include "StartScreen.h"
#include "CharacterScreen.h"
#include "Game.h"
#include "GameScreen.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    int playerCharacter = 2;
    int compCharacter = 2;

    // Configuring Window
    QMainWindow w;
    w.setWindowTitle("Battle Arena");
    w.resize(900, 650);

    QWidget *centralWidget = new QWidget(&w);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    QStackedWidget *stackedWidget = new QStackedWidget;

    Game* game = new Game(stackedWidget);
    StartScreen startPage(stackedWidget, &a, game);
    CharacterScreen characterPage(stackedWidget, game);
    //GameScreen gamePage(stackedWidget, playerCharacter, compCharacter);

    // Add Views to Stacked Widget
    stackedWidget->addWidget(startPage.getPage());
    stackedWidget->addWidget(characterPage.getPage());
    
    //stackedWidget->addWidget(gamePage.getPage());

    // Display the first view
    stackedWidget->setCurrentIndex(0);

    mainLayout->addWidget(stackedWidget);
    w.setCentralWidget(centralWidget);
    w.show();

    return a.exec();
}
