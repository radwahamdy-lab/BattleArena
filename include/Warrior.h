#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>

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

class Warrior : public Character {
	public:
        Warrior();
        void attack(bool isSpecial) override;
};
#endif
