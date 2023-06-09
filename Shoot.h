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
    sf::Sprite bullet;
    char turn;
public:
    Shoot(sf::RenderWindow& windowArg, sf::Texture& textureArg, float unitCenter, float unitY, bool up);
    void updateBullet();
    float getDiameter() const;
    sf::Vector2f getCenter() const;
    bool destroyMe() const;
};


#endif //SPACE_SHOOTER_SHOOT_H
