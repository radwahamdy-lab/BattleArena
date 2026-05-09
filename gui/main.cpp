#include <QApplication>
#include <QStackedWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QMainWindow>
#include "StartScreen.h"
#include "CharacterScreen.h"
#include "GameScreen.h"
#include "game.h"

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

    StartScreen startPage(stackedWidget, &a);
    CharacterScreen characterPage(stackedWidget);


    // Add Views to Stacked Widget
    stackedWidget->addWidget(startPage.getPage());
    stackedWidget->addWidget(characterPage.getPage());

    Game* game = new Game( // Temporary until character selection is connected properly
        characterPage.getUserCharacter(),
        characterPage.getComputerCharacter()
        );

    game->startGame();

    stackedWidget->addWidget(game->getGameScreen()->getPage());

    // Display the first view
    stackedWidget->setCurrentIndex(0);

    mainLayout->addWidget(stackedWidget);
    w.setCentralWidget(centralWidget);
    w.show();

    return a.exec();
}
