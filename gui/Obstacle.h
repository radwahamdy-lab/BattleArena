#pragma once
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QPixmap>
#include <QObject>
#include <vector>
using namespace std;

class Obstacle : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT

    public:
        static vector<Obstacle*> obs;
        Obstacle(QGraphicsScene*, QPointF, QPointF);
        bool isOnPlayer(QPointF, QPointF);
        bool isOnObstacle(QPointF);
    private:
        QGraphicsScene* scene;
        QPixmap vertical1 = QPixmap(":walls/Castle_vertical31.png");

};

