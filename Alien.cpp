//
// Created by indianajones on 5/14/23.
//

#include "Alien.h"

Alien::Alien(sf::RenderWindow &windowArg, sf::Texture &textureArg, float x, float y, float size): Unit{windowArg, textureArg}, window(windowArg) {
    hpMax = 5;
    damage = 5;
    loadTexture();
    setEnemyPosistion(x, y);
    setSize(size);
}

void Alien::updateAlien() {
    moveY(0.3, true);
//    rotate(90);
    showSprite();
}
