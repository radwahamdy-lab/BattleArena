#include <QApplication>
#include <QStackedWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QMainWindow>
#include "StartScreen.h"
#include "CharacterScreen.h"

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

    StartScreen startPage(stackedWidget, &a);
    CharacterScreen characterPage(stackedWidget);

    // Add Views to Stacked Widget
    stackedWidget->addWidget(startPage.getPage());
    stackedWidget->addWidget(characterPage.getPage());

    // Display the first view
    stackedWidget->setCurrentIndex(0);

    mainLayout->addWidget(stackedWidget);
    w.setCentralWidget(centralWidget);
    w.show();

    return a.exec();
}
