#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>

<<<<<<< HEAD
class Warrior : public QGraphicsItem {
public:
    Warrior() {
        pixmap.load(":/warrior_idle.png");
    }
    
    // Defines the area the item covers
    QRectF boundingRect() const override {
        return QRectF(0, 0, pixmap.width(), pixmap.height());
    }
    
    // Handles the actual painting
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override {
        painter->drawPixmap(0, 0, pixmap);
    }

private:
    QPixmap pixmap;
};
=======
class Warrior : public Character {
	public:
        Warrior();
        void attack(bool isSpecial) override;
};
#endif
>>>>>>> 04647ee6b9033dee857a1f8d951387c2bd349fc3
