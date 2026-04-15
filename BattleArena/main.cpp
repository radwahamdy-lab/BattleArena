#include "mainwindow.h"
#include <QApplication>
#include <QStackedWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QMainWindow>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Configuring Window
    QMainWindow w;
    w.setWindowTitle("Battle Arena");
    w.resize(400, 300);

    QWidget *centralWidget = new QWidget(&w);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    QStackedWidget *stackedWidget = new QStackedWidget;

    // View 1: Start Menu
    QWidget *startPage = new QWidget;
    QVBoxLayout *startLayout = new QVBoxLayout(startPage);

    QPushButton *newGameBtn = new QPushButton("New Game");
    QPushButton *contGameBtn = new QPushButton("Continue Game");
    QPushButton *exitBtn = new QPushButton("Exit");

    startLayout->addWidget(newGameBtn);
    startLayout->addWidget(contGameBtn);
    startLayout->addWidget(exitBtn);

    // View 2: Character Select
    QWidget *characterPage = new QWidget;
    QVBoxLayout *characterLayout = new QVBoxLayout(characterPage);
    characterLayout->addWidget(new QLabel("Select a Character"));

    //Add Views to Stacked Widget
    stackedWidget->addWidget(startPage);
    stackedWidget->addWidget(characterPage);

    // Display the first view
    stackedWidget->setCurrentIndex(0);

    //Connect New Game button to Character Select View
    QObject::connect(newGameBtn, &QPushButton::clicked, [stackedWidget]() {
        stackedWidget->setCurrentIndex(1);
    });

    QObject::connect(exitBtn, &QPushButton::clicked, &a, &QApplication::quit);

    mainLayout->addWidget(stackedWidget);
    w.setCentralWidget(centralWidget);
    w.show();

    return a.exec();
}
