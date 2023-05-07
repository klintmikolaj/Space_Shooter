
#ifndef SPACE_SHOOTER_SHOOT_H
#define SPACE_SHOOTER_SHOOT_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include <vector>

class Shoot
{
private:
    sf::RenderWindow& window;
    sf::Texture& texture;
    Player& player;
    sf::Sprite bullet;
    char turn;
public:
    Shoot(sf::RenderWindow& windowArg, sf::Texture& textureArg, Player& playerArg, bool up);
    void updateBullet();
    float getX() const;
    float getY() const;
    bool destroyMe() const;
};


#endif //SPACE_SHOOTER_SHOOT_H
