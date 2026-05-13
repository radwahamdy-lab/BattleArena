#include "GameScreen.h"
#include "Character.h"
#include "Scoreboard.h"
#include "Obstacle.h"

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
#include <QPushButton>

#include <functional>
#include <string>
#include <vector>
#include <QDebug>

using namespace std;

GameScreen::GameScreen(QStackedWidget* stackedwid, int playerCharacter, int compCharacter){

    QVBoxLayout* layout = new QVBoxLayout(gamePage);

    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 800, 600);

    QGraphicsView *view = new QGraphicsView(scene);

    // Quit Button
    QPushButton* quitButton = new QPushButton("Quit");
    quitButton->setFixedHeight(50);

    QObject::connect(quitButton, &QPushButton::clicked, []() {

        qDebug() << "BUTTON WORKS";
    });

    quitButton->setStyleSheet(
        "font: 16pt 'JetBrainsMono Nerd Font Propo';"
        "color: white;"
        "background-color: rgb(120, 30, 30);"
        );

    // Quit Button Logic
    QObject::connect(quitButton, &QPushButton::clicked, [this]() {

        if(quitCallback)
            quitCallback();
    });

    // Drawing Background
    QPixmap grassTile(":/grass_block.png");
    scene->setBackgroundBrush(QBrush(grassTile));

    // Drawing Timer
    timerText = new QGraphicsTextItem();

    QFont timer_font("JetBrainsMono Nerd Font Propo", 35, QFont::Bold);

    timerText->setDefaultTextColor(QColor(229, 68, 9));
    timerText->setFont(timer_font);
    timerText->setPos(350, 10);
    timerText->setPlainText("3:00");

    scene->addItem(timerText);

    timerText->setZValue(1);

    // Creating Timer
    QTimer *sec = new QTimer();

    QObject::connect(sec, &QTimer::timeout, [sec, this](){

        if(time != 0){

            time--;

            int minutes = this->time / 60;
            int seconds = this->time % 60;

            string seconds_str =
                to_string(seconds).length() == 1
                    ? "0" + to_string(seconds)
                    : to_string(seconds);

            string time_str =
                to_string(minutes) + ":" + seconds_str;

            QString time_qt =
                QString::fromStdString(time_str);

            timerText->setPlainText(time_qt);

            sec->start(1000);
        }
    });

    sec->start(1000);

    // Creating Characters
    player = new Character(scene, playerCharacter, false);

    scene->addItem(player);

    player->setFocus();

    comp = new Character(scene, compCharacter, true);

    scene->addItem(comp);

    player->setEnemy(comp);

    comp->setEnemy(player);

    // Scoreboard
    scoreboard = new Scoreboard(scene, player, comp);

    // Obstacles
    for(int i = 0; i < obstacles_num; i++){

        Obstacle* obs =
            new Obstacle(scene, player->pos(), comp->pos());

        obstacles.push_back(obs);
    }

    player->setObstacles(obstacles);

    comp->setObstacles(obstacles);

    view->setCacheMode(QGraphicsView::CacheBackground);

    layout->addWidget(view);

    layout->addWidget(quitButton);

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