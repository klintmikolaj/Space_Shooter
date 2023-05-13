//
// Created by indianajones on 5/7/23.
//

#include "Asteroid.h"
using namespace sf;

Asteroid::Asteroid(RenderWindow & windowArg, sf::Texture & textureArg, float x, float y): Unit{windowArg, textureArg}, window(windowArg)
{
    hpMax = 2;
    damage = 1;
    speed = 10;
    loadTexture();
    setEnemyPosistion(x, y);
}


void Asteroid::updateAsteroid() {
    moveY(0.1);
//    rotate(1);
    showSprite();
}
