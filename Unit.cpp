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


void Unit::moveX(float px, bool direction)
{
    bool visible;
    if(direction)
    {
        visible= window.getSize().x - sprite.getPosition().x - px - texture.getSize().x / 2 > 0;
    }
    else
    {
        px=-px;
        visible= (sprite.getPosition().x + texture.getSize().x / 2 + px) >= 0;
    }
    if(visible)
        sprite.move(px, 0);
//    window.draw(sprite);
//    window.display();
}

void Unit::moveY(float px, bool direction)
{
    char turn;
    direction?turn=1:turn=-1;
    sprite.move(0, px*0.5*turn);
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


Vector2f Unit::getCenter() const
{
    Vector2f a(texture.getSize().x/2,texture.getSize().y/2);
    return sprite.getPosition()+a;
}

Vector2f Unit::getBounds() const
{
    Vector2f a(texture.getSize().x,texture.getSize().y);
    return a;
}

float modulo(float a)
{
    if(a<0)
        return -a;
    return a;
}

bool Unit::collision(sf::Vector2f centerV, sf::Vector2f boundsV) const
{
    if(modulo(getCenter().x - centerV.x) < (texture.getSize().x/2 - boundsV.x/2) && modulo(getCenter().y - centerV.y) < (texture.getSize().y/2 - boundsV.y/2))
        return true;
    return false;
}

bool Unit::collision(sf::Vector2f centerV, float diameter) const
{
    if(modulo(getCenter().x - centerV.x) < (texture.getSize().x/2 - diameter/2) && modulo(getCenter().y - centerV.y) < (texture.getSize().y/2 - diameter/2))
        return true;
    return false;
}

bool Unit::killMe() const
{
    if(sprite.getPosition().y-window.getSize().y>0)
        return true;
    return false;
}

bool Unit::isDead() const
{
    if(hp>0)
        return false;
    return true;
}