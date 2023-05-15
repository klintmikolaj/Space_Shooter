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


void Unit::moveX(char px, bool direction)
{
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

void Unit::moveY(float px)
{
    sprite.move(0, px*0.6);
}

//void Unit::moveCircular(int rad, bool direction) {
//
//    sprite.move
//}

void Unit::rotate(int ang) {
    sprite.rotate(ang);
}


void Unit::loadTexture()
{
    sprite.setTexture(texture);
}

void Unit::setPlayerPosition()
{
    sprite.setPosition(((float)window.getSize().x - (float)texture.getSize().x) / 2, (float)window.getSize().y - (float)texture.getSize().y);
}

void Unit::setEnemyPosistion(float x, float y)
{
    sprite.setPosition(x, y);
}

void Unit::setSize(float size) {
    sprite.setScale(size, size);
}

void Unit::showSprite()
{
    window.draw(sprite);
}

void Unit::decreaseHP()
{
    if(hp>0)
        hp--;
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


Vector2f Unit::center() const
{
    Vector2f a(texture.getSize().x/2,texture.getSize().y/2);
    return sprite.getPosition()+a;
}

float modulo(float a)
{
    if(a<0)
        return -a;
    return a;
}

bool Unit::collision(sf::Vector2f a) const
{
    if(modulo(center().x-a.x)<texture.getSize().x/2&&modulo(center().y-a.y)<texture.getSize().y/2)
        return true;
    return false;
}

bool Unit::killMe() const
{
    if(sprite.getPosition().y-window.getSize().y>0)
        return true;
    return false;
}
