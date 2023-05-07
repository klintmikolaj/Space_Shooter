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
    const float randomShit=0.2;
    bullet.move(0,turn*randomShit);
    window.draw(bullet);
}
