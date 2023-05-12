//
// Created by Bartłomiej Pruszczyk on 07/05/2023.
//

#include <SFML/Graphics.hpp>
#include "Unit.h"

using namespace std;
using namespace sf;

Unit::Unit(RenderWindow & windowArg, sf::Texture & textureArg):Unit(windowArg,textureArg,3)
{

}

Unit::Unit(RenderWindow & windowArg, sf::Texture & textureArg, int hpArg):window(windowArg),texture(textureArg),hp(hpArg)
{

}

void Unit::move(bool direction, bool isSkip)
{
    char px=20;
    if(isSkip)
        px*=5;
    bool visible;
    if(direction)
    {
        visible= window.getSize().x - sprite.getPosition().x - px - texture.getSize().x / 2 > 0;
    }
    else
    {
        px=(char)-px;
        visible= (sprite.getPosition().x + texture.getSize().x / 2 + px) >= 0;
    }
    if(visible)
        sprite.move(px, 0);
    showSprite();
}

void Unit::loadTexture()
{
    sprite.setTexture(texture);
    sprite.setPosition(((float)window.getSize().x - (float)texture.getSize().x) / 2, (float)window.getSize().y - (float)texture.getSize().y);
}

void Unit::showSprite()
{
    window.draw(sprite);
}

int Unit::getHP() const
{
    return hp;
}

float Unit::getXLeft() const
{
    return sprite.getPosition().x;
}

float Unit::getXCenter() const
{
    return sprite.getPosition().x + texture.getSize().x / 2;
}

float Unit::getY() const
{
    return sprite.getPosition().y;
}