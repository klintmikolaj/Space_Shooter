//
// Created by indianajones on 4/29/23.
//

#include "Shoot.h"
#include <iostream>

Shoot::Shoot(sf::RenderWindow &windowArg, sf::Texture& textureArg, float unitCenter, float unitY, bool up): window(windowArg), texture(textureArg)
{
    if(up)
        turn=-1;
    else
        turn=1;
    bullet.setTexture(textureArg);
    bullet.setPosition(unitCenter - textureArg.getSize().x / 2, unitY);
}


void Shoot::updateBullet()
{
    const float randomShit=0.7;
    bullet.move(0,turn*randomShit);
    window.draw(bullet);
//    std::cout<<bullet.getPosition().x<<";"<<bullet.getPosition().y<<"\t";
}

float Shoot::getDiameter() const
{
    return texture.getSize().x;
}

sf::Vector2f Shoot::getCenter() const
{
    sf::Vector2f s(11,11);
    return bullet.getPosition()+s;
}

bool Shoot::destroyMe() const
{
    if(bullet.getPosition().y+texture.getSize().y<0)
        return true;
    return false;
}
