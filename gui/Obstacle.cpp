#include "Obstacle.h"
#include <QRandomGenerator>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

#include <vector>
#include <cmath>
using namespace std;

vector<Obstacle*> Obstacle::obs;

Obstacle::Obstacle(QGraphicsScene* sc, QPointF char1_pos, QPointF char2_pos) : scene(sc) {
    QPointF position;
    do{
        position.setX(QRandomGenerator::global()->bounded(0, 720));
        position.setY(QRandomGenerator::global()->bounded(0, 495));
    } while (isOnPlayer(position, char1_pos) || isOnPlayer(position, char2_pos));

    setPos(position);
    setPixmap(vertical1);
    scene->addItem(this);
    obs.push_back(this);
}

bool Obstacle::isOnPlayer(QPointF planned_pos, QPointF player_pos){
    return (abs(planned_pos.x() - player_pos.x()) < 50) && (abs(planned_pos.y() - player_pos.y()) < 50);
}

bool Obstacle::isOnObstacle(QPointF planned_pos){
    bool verdict = false;
    for(int i=0; i<obs.size() && !verdict; i++)
        if ((abs(planned_pos.x() - obs[i]->x()) < 50) && (abs(planned_pos.y() - obs[i]->y()) < 50))
            verdict = true;
    return verdict;
}