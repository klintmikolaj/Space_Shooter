//
// Created by indianajones on 4/29/23.
//

#include "Shoot.h"
#include <iostream>

Shoot::Shoot(sf::RenderWindow &windowArg, sf::Texture& textureArg, Player& playerArg, bool up):window(windowArg), texture(textureArg), player(playerArg)
{
    if(up)
        turn=-1;
    else
        turn=1;
    bullet.setTexture(textureArg);
    bullet.setPosition(player.getXCenter()-textureArg.getSize().x/2,player.getY());
}


void Shoot::updateBullet()
{
    const float randomShit=0.18;
    bullet.move(0,turn*randomShit);
    window.draw(bullet);
    std::cout<<bullet.getPosition().x<<";"<<bullet.getPosition().y<<"\t";
}

float Shoot::getX() const
{
    return bullet.getPosition().x;
}

float Shoot::getY() const
{
    return bullet.getPosition().y;
}

bool Shoot::destroyMe() const
{
    if(bullet.getPosition().y+texture.getSize().y<0)
        return true;
    return false;
}