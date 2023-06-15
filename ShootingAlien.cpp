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
    float T = tick/100.f; //okres
    int x = 2;
    float z = cos((T/(5*x)));
    int multiplier = z > 0 ? 0: sin(T/(2*x)) > 0?1:-1;
    float speed = pow(cos(T/10000), 2) * 0.1;
//    cout << T << " " << z << " " << multiplier << " " << speed << endl;
    move(speed * multiplier, 0, true, true, true);
    //    cout << 1 * multiplier << x << speed << endl;
    tick += 1;
}