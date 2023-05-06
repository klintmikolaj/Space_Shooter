
#ifndef SPACE_SHOOTER_SHOOT_H
#define SPACE_SHOOTER_SHOOT_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include <vector>

class Shoot
{
private:
    sf::RenderWindow& window;
    sf::Texture& bulletTexture;

public:
    explicit Shoot(sf::RenderWindow& windowArg, sf::Texture& textureArg);
    void makeShoot(Player& playerArg, bool turn);
    void updateBullets();

};


#endif //SPACE_SHOOTER_SHOOT_H
