#ifndef SPACE_SHOOTER_ASTEROID_H
#define SPACE_SHOOTER_ASTEROID_H
#include <SFML/Graphics.hpp>
#include "Unit.h"

class Asteroid: public Unit {
public:
    Asteroid(sf::RenderWindow & windowArg, sf::Texture & textureArg, float x, float y, float size);
    void updateAsteroid();
//    Asteroid randomTexture(sf::Texture, sf::Texture);
private:
    sf::RenderWindow& window;
    int hpMax;
    int damage; /* jaki zadaje spritowi gracza */
    float speed;
    int spawnNow;
    int spawnCooldown;
};

#endif