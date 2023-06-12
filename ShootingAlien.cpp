//
// Created by IndianaJones on 19/05/2023.
//

#include "ShootingAlien.h"
#include <cmath>
#include <iostream>
using namespace std;
ShootingAlien::ShootingAlien(sf::RenderWindow & windowArg, sf::Texture & textureArg, float x, float y, float size, int pointsForPlayerArg, float speedArg):Alien{windowArg, textureArg, x, y, size, pointsForPlayerArg, speedArg}
{
    tick = 0;
}

void ShootingAlien::update()
{
    Enemies::update();
    float period = tick/100.f;
    int test = 2;
    float z = cos((period/(5*test)));
    int multiplier = z > 0 ? 0: sin(period/(2*test)) > 0?1:-1;
    float speed = pow(cos(period/10000), 2) * 0.1;
    moveX(speed * multiplier, true);
    tick += 1;
}