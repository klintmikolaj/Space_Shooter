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

    /*
     * moving and drawing the bullet
    */
    void updateBullet();

    /*
     * returns the width of the texture
    */
    float getDiameter() const;

    /*
     * returns the new position of the bullet
     * the position is in the center of the player sprite
    */
    sf::Vector2f getCenter() const;

    /*
     * returning the boll value representing if bullet is destroyed or not
    */
    bool destroyMe() const;
};


#endif //SPACE_SHOOTER_SHOOT_H
