#ifndef SPACE_SHOOTER_ENEMIES_H
#define SPACE_SHOOTER_ENEMIES_H

#include <SFML/Graphics.hpp>
#include "Unit.h"

class Enemies: public Unit {
public:
    Enemies(sf::RenderWindow& windowArg, sf::Texture& textureArg, float speedArg, int pointsForPlayerArg);

    void update();

    int getPoints() const;

protected:
    float speed;

private:
    int pointsForPlayer;
};

#endif