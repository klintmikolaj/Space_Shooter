#ifndef SPACE_SHOOTER_ENEMIES_H
#define SPACE_SHOOTER_ENEMIES_H

#include <SFML/Graphics.hpp>
#include "Unit.h"

class Enemies: public Unit {
public:
    Enemies(sf::RenderWindow& windowArg, sf::Texture& textureArg, float speedArg, int pointsForPlayerArg);

    /*
     * Updates the enemy
     */
    void update();

    /*
     * Function returns number of points which will be subtracted from players HP
     */
    int getPoints() const;

protected:
    float speed;

private:
    int pointsForPlayer;
};

#endif
