#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QStackedWidget>
#include <QObject>
#include <QLabel>
#include <QApplication>
#include "StartScreen.h"

StartScreen::StartScreen(QStackedWidget* stackedwid, QApplication* a){
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

    QObject::connect(contGameBtn, &QPushButton::clicked, [stackedwid](){
        stackedwid->setCurrentIndex(2);
    });

    QObject::connect(exitBtn, &QPushButton::clicked, a, &QApplication::quit);

}

QWidget* StartScreen::getPage(){
    return startPage;
}