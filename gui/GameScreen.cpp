#include "GameScreen.h"
#include "Character.h"
#include "Scoreboard.h"
#include "Character.h"
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

#include <string>
#include <vector>
using namespace std;


GameScreen::GameScreen(QStackedWidget* stackedwid) : QObject(){
    QVBoxLayout* layout = new QVBoxLayout(gamePage);

    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 800, 600);
    view = new QGraphicsView(scene);

    // Drawing Bckground
    QPixmap grassTile(":/grass_block.png");
    scene->setBackgroundBrush(QBrush(grassTile));

    // Drawing Timer
    timerText = new QGraphicsTextItem();
    QFont timer_font("JetBrainsMono Nerd Font Propo", 35, QFont::Bold);
    timerText->setDefaultTextColor(QColor(229, 68, 9));
    timerText->setFont(timer_font);
    timerText->setPos(350, 10);
    scene->addItem(timerText);
    timerText->setZValue(1);

    // Quit Button
    quitButton = new QPushButton("Quit");
    quitButton->setStyleSheet(
        "font: 16pt 'JetBrainsMono Nerd Font Propo';"
        "color: white;"
        "background-color: rgb(120, 30, 30);"
    );
    quitButton->setFixedHeight(50);
    QObject::connect(quitButton, &QPushButton::clicked, [this]() {
        emit quitButtonClicked();
    });

    
    view->setCacheMode(QGraphicsView::CacheBackground);

    layout->addWidget(view);
    layout->addWidget(quitButton);

}

void GameScreen::startGame(int playerCharacter, int compCharacter){
    // Creating Character
    player = new Character(scene, playerCharacter, false);
    scene->addItem(player);
    player->setFocus();

    comp = new Character(scene, compCharacter, true);
    scene->addItem(comp);

    player->setEnemy(comp);
    comp->setEnemy(player);

    scoreboard = new Scoreboard(scene, player, comp);

    for(int i=0; i<obstacles_num; i++){
        Obstacle* obs = new Obstacle(scene, player->pos(), comp->pos());
        obstacles.push_back(obs);
    }

    player->setObstacles(obstacles);
    comp->setObstacles(obstacles);
    view->show();


}

QWidget* GameScreen::getPage(){
    return gamePage;
}

void GameScreen::updateTimer(QString text){
    timerText->setPlainText(text);
    if(text == "GAME OVER"){
        timerText->setPos(250, 250);
    }
}

Character* GameScreen::getPlayer(){
    return player;
}

Character* GameScreen::getComp(){
    return comp;
}
