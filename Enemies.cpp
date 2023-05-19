#include "Enemies.h"

using namespace sf;

Enemies::Enemies(RenderWindow & windowArg, Texture & textureArg, float speedArg, int pointsForPlayerArg): Unit{windowArg,textureArg}, speed(speedArg), pointsForPlayer(pointsForPlayerArg)
{
}

void Enemies::update() {
    moveY(0.1*speed,true);
    showSprite();
}

int Enemies::getPoints() const
{
    return pointsForPlayer;
}
