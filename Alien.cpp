//
// Created by indianajones on 5/14/23.
//

#include "Alien.h"
//#include <iostream>
#include <cmath>

using namespace std;

Alien::Alien(sf::RenderWindow &windowArg, sf::Texture &textureArg, float x, float y, float size, int pointsForPlayerArg, float speedArg): Enemies{windowArg, textureArg,speedArg,pointsForPlayerArg}, window{windowArg}
{
    loadTexture();
    setEnemyPosistion(x, y);
    setSize(size);
    tick = 0;
}

void Alien::updateAlien() {
    float x = tick/5;
    int z = sin((x/10) + (M_PI/2));
    int multiplier = z > 0 ? 0: sin(x/10) > 0?1:-1;
    int speed = cos(x/100) * 1.2;
    moveX(speed * multiplier, true);
//    cout << 1 * multiplier << x << speed << endl;
    tick += 1;
}
