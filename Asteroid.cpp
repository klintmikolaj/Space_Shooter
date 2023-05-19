//
// Created by indianajones on 5/7/23.
//

#include "Asteroid.h"
using namespace sf;

Asteroid::Asteroid(RenderWindow & windowArg, sf::Texture & textureArg, float x, float y, float size): Enemies{windowArg, textureArg,1,2}, window(windowArg)
{
    loadTexture();
    setEnemyPosistion(x, y);
    setSize(size);
}

