#ifndef SPACE_SHOOTER_ASTEROID_H
#define SPACE_SHOOTER_ASTEROID_H
#include <SFML/Graphics.hpp>
#include "Enemies.h"

class Asteroid: public Enemies
{
public:
    Asteroid(sf::RenderWindow & windowArg, sf::Texture & textureArg, float x, float y, float size);
    void updateAsteroid();

private:
    sf::RenderWindow& window;
    int hpMax;
     int damage; /* jaki zadaje spritowi gracza */
};

#endif