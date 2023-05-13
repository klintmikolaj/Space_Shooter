#ifndef SPACE_SHOOTER_SHOOT_H
#define SPACE_SHOOTER_SHOOT_H

#include <SFML/Graphics.hpp>
#include "Unit.h"
#include <vector>

class Shoot
{
private:
    sf::RenderWindow& window;
    sf::Texture& texture;
    Unit& unit;
    sf::Sprite bullet;
    char turn;
public:
    Shoot(sf::RenderWindow& windowArg, sf::Texture& textureArg, Unit& unitArg, bool up);
    void updateBullet();
    float getX() const;
    float getY() const;
    void destroyMe();
    bool destroyMeBool() const;
    virtual ~Shoot();
};


#endif //SPACE_SHOOTER_SHOOT_H
