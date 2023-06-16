#ifndef SPACE_SHOOTER_ASTEROID_H
#define SPACE_SHOOTER_ASTEROID_H
#include <SFML/Graphics.hpp>
#include "Enemies.h"

class Asteroid: public Enemies
{
    float spawnCooldown=200;
public:
    Asteroid(sf::RenderWindow * windowArg, sf::Texture * textureArg, float x, float y, float size, float speed);
};

#endif