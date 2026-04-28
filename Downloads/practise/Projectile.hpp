#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP
#include "Position.hpp"
#include "Character.hpp"


class Projectile {
private:
    double speed;
    Position position;
    int scoreIncrement;
    double size;

public:
    Projectile(double speed, Position position, int scoreIncrement, double size);

    bool isCollide(const Character& target) const;
    void move();

    Position getPosition() const;
};

#endif