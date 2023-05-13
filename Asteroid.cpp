//
// Created by indianajones on 5/7/23.
//

#include "Asteroid.h"
using namespace sf;

Asteroid::Asteroid(RenderWindow & windowArg, sf::Texture & textureArg): Unit{windowArg, textureArg}, window(windowArg)
{
    hpMax = 2;
    damage = 1;
    speed = 0.1;
}

void Asteroid::updateAsteroid() {
    moveX(0, speed);
    showSprite();
}