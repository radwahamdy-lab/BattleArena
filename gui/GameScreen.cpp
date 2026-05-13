#include "GameScreen.h"
#include <QStackedWidget>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPixmap>
#include <QBrush>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsTextItem>
#include <QString>
#include <QFont>
#include <string>
#include "Character.h"

using namespace std;

GameScreen::GameScreen(QStackedWidget* stackedwid, int playerCharacter, int compCharacter){
    QVBoxLayout* layout = new QVBoxLayout(gamePage);

    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 800, 600);
    QGraphicsView *view = new QGraphicsView(scene);
    QPushButton* quitButton = new QPushButton("Quit");
    quitButton->setStyleSheet(
        "font: 16pt 'JetBrainsMono Nerd Font Propo';"
        "color: white;"
        "background-color: rgb(120, 30, 30);"
        );

    // Drawing Bckground
    QPixmap grassTile(":/grass_block.png");
    scene->setBackgroundBrush(QBrush(grassTile));

    // Drawing Timer
    timerText = new QGraphicsTextItem(); // encapsulation, so that other classes can access timerText
    QFont timer_font("JetBrainsMono Nerd Font Propo", 35, QFont::Bold);
    timerText->setDefaultTextColor(QColor(229, 68, 9));
    timerText->setFont(timer_font);
    timerText->setPos(350, 10);
    timerText->setPlainText("3:00");
    scene->addItem(timerText);

    // Creating Character
    player = new Character(scene, 2, false);
    scene->addItem(player);
    player->setFocus();

    comp = new Character(scene, 2, true);
    scene->addItem(comp);

    player->setEnemy(comp);
    comp->setEnemy(player);

    view->setCacheMode(QGraphicsView::CacheBackground);

    layout->addWidget(view);
    layout->addWidget(quitButton);
    QObject::connect(quitButton, &QPushButton::clicked, [this]() {

        if(quitCallback)
            quitCallback();
    });
    view->show();
    view->setFocusPolicy(Qt::StrongFocus);
    view->setFocus();
    player->setFocus();

}

QWidget* GameScreen::getPage(){
    return gamePage;
}

void GameScreen::updateTimer(QString text){
    timerText->setPlainText(text);
}

void GameScreen::setQuitCallback(function<void()> callback){
    quitCallback = callback;
}

Character* GameScreen::getPlayer(){
    return player;
}

Character* GameScreen::getComp(){
    return comp;
}