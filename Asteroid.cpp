//
// Created by indianajones on 5/7/23.
//

#include "Asteroid.h"
using namespace sf;

Asteroid::Asteroid(RenderWindow & windowArg, sf::Texture & textureArg, float x, float y, float size): Unit{windowArg, textureArg}, window(windowArg)
{
    hpMax = 2;
    damage = 1;
    loadTexture();
    setEnemyPosistion(x, y);
    setSize(size);
}


void Asteroid::updateAsteroid() {
    moveY(0.1);
//    rotate(1);
    showSprite();
}

