//
// Created by indianajones on 5/14/23.
//

#include "Enemies.h"
#include "Alien.h"

Alien::Alien(sf::RenderWindow &windowArg, sf::Texture &textureArg, float x, float y, float size): Enemies{windowArg, textureArg,5}, window{windowArg} {
    hpMax = 5;
    damage = 5;
    loadTexture();
    setEnemyPosistion(x, y);
    setSize(size);
}

void Alien::updateAlien() {
    moveY(0.3, true);
//    rotate(1);
    showSprite();
}
