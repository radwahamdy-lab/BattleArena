#include <QApplication>
#include <QStackedWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QMainWindow>
#include "StartScreen.h"
#include "CharacterScreen.h"
#include "GameScreen.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    int playerCharacter = 3;
    int compCharacter = 2;

    // Configuring Window
    QMainWindow w;
    w.setWindowTitle("Battle Arena");
    w.resize(900, 650);

    QWidget *centralWidget = new QWidget(&w);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    QStackedWidget *stackedWidget = new QStackedWidget;

    StartScreen startPage(stackedWidget, &a);
    GameScreen gamePage(stackedWidget, playerCharacter, compCharacter);


    // Add Views to Stacked Widget
    stackedWidget->addWidget(startPage.getPage());
    stackedWidget->addWidget(gamePage.getPage());

    // Display the first view
    stackedWidget->setCurrentIndex(0);

    mainLayout->addWidget(stackedWidget);
    w.setCentralWidget(centralWidget);
    w.show();

    return a.exec();
}
