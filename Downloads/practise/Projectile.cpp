#include "Projectile.hpp"
#include <cmath>
using namespace std;

Projectile::Projectile(double speed, Position position, int scoreIncrement, double size)
    : speed(speed), position(position), scoreIncrement(scoreIncrement), size(size) {}

void Projectile::move() {
    position = Position(position.getX() + speed,
                        position.getY());
}

bool Projectile::isCollide(const Character& target) const {
    double dx = position.getX() - target.getPosition().getX();
    double dy = position.getY() - target.getPosition().getY();

    double distance = sqrt(dx * dx + dy * dy);

    return distance < size;
}

Position Projectile::getPosition() const {
    return position;
}