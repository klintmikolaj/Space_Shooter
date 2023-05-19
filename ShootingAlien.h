//
// Created by Bartłomiej Pruszczyk on 19/05/2023.
//

#ifndef SPACE_SHOOTER_SHOOTINGALIEN_H
#define SPACE_SHOOTER_SHOOTINGALIEN_H

#include "Alien.h"

class ShootingAlien: public Alien
{
    public:
        ShootingAlien(sf::RenderWindow & windowArg, sf::Texture & textureArg, float x, float y, float size, int pointsForPlayerArg, float speedArg);
        void updateShootingAlien();
private:
    int tick1;
    int tick2;
};


#endif //SPACE_SHOOTER_SHOOTINGALIEN_H
