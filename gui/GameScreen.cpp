#include "GameScreen.h"
#include "Character.h"
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
<<<<<<< HEAD
#include "Scoreboard.h"
#include "Character.h"
=======
>>>>>>> c8769ae70a8f53fa3c3abf9192524ff85226bd11
using namespace std;


GameScreen::GameScreen(QStackedWidget* stackedwid, int playerCharacter, int compCharacter){
    QVBoxLayout* layout = new QVBoxLayout(gamePage);

    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 800, 600);
    QGraphicsView *view = new QGraphicsView(scene);

    // Drawing Bckground
    QPixmap grassTile(":/grass_block.png");
    scene->setBackgroundBrush(QBrush(grassTile));

    // Drawing Timer
    QGraphicsTextItem *timerText = new QGraphicsTextItem();
    QFont timer_font("JetBrainsMono Nerd Font Propo", 35, QFont::Bold);
    timerText->setDefaultTextColor(QColor(229, 68, 9));
    timerText->setFont(timer_font);
    timerText->setPos(350, 10);
    timerText->setPlainText("3:00");
    scene->addItem(timerText);

    // Creating Timer
    QTimer *sec = new QTimer();
    QObject::connect(sec, &QTimer::timeout, [sec, this, timerText](){
        if(time != 0){
            time--;
            int minutes = this->time/60;
            int seconds = this->time%60;
            string seconds_str = to_string(seconds).length()==1 ? "0"+to_string(seconds) : to_string(seconds);
            string time_str = to_string(minutes) + ":" + seconds_str;
            QString time_qt = QString::fromStdString(time_str);
            timerText->setPlainText(time_qt);
            sec->start(1000);
        }
    });
    sec->start(1000);

    // Creating Character
    player = new Character(scene, playerCharacter, false);
    scene->addItem(player);
    player->setFocus();

    comp = new Character(scene, compCharacter, true);
    scene->addItem(comp);

    player->setEnemy(comp);
    comp->setEnemy(player);

    scoreboard = new Scoreboard(scene, player, comp);

    view->setCacheMode(QGraphicsView::CacheBackground);

    layout->addWidget(view);
    view->show();

}

QWidget* GameScreen::getPage(){
    return gamePage;
}
