//
// Created by indianajones on 5/7/23.
//

#include "Asteroid.h"
using namespace sf;

Asteroid::Asteroid(RenderWindow * windowArg, sf::Texture * textureArg, float x, float y, float size, float speed): Enemies{windowArg, textureArg,speed,2}
{
    loadTexture();
    setEnemyPosistion(x, y);
    setSize(size);
}

