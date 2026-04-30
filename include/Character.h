#ifndef CHARACTER_H
#define CHARACTER_H

#include <QGraphicsRectItem>
#include <QBrush>
#include <QKeyEvent>
#include <string>

class Character : public QGraphicsRectItem {
    private:
        int score;
        int speed;
        static int characterCount;
    protected:
        void keyPressEvent(QKeyEvent *event) override;
    public:
        Character(int newScore = 0, int speed = 10);
        virtual ~Character();

        int getScore() const {
		return score;
	}
        int getSpeed() const {
		return speed;
	}
        static int getCharacterCount();

        virtual int attack(bool isSpecial) const = 0;
        void scoreInc(int amount);
};

#endif
