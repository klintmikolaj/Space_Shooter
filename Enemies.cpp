#include "Enemies.h"

using namespace sf;

Enemies::Enemies(RenderWindow & windowArg, Texture & textureArg, float speedArg, int pointsForPlayerArg): Unit{windowArg,textureArg}, speed(speedArg), pointsForPlayer(pointsForPlayerArg)
{
}

void Enemies::update() {
    move(0,0.1*speed,true,true, true);
    showSprite();
}

int Enemies::getPoints() const
{
    return pointsForPlayer;
}
