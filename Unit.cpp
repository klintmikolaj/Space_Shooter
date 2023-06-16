//
// Created by Bartłomiej Pruszczyk on 07/05/2023.
//

#include <SFML/Graphics.hpp>
#include "Unit.h"

using namespace std;
using namespace sf;


Unit::Unit(RenderWindow * windowArg, sf::Texture * textureArg):window(windowArg),texture(textureArg)
{
}

bool Unit::visible(sf::Vector2f position, sf::Vector2f movement)
{
    Vector2f afterMovement=position+movement;
    if(afterMovement.x>1000||afterMovement.x<0||afterMovement.y<0||afterMovement.y>800)
        return false;
    return true;
}

void Unit::move(float x, float y, bool dirX, bool dirY, bool isAlien)
{
    char ax=dirX?1:-1;
    char ay=dirY?1:-1;
    Vector2f movement(ax*x,ay*y);
    if(isAlien||visible(getCenter(), movement))
    {
        sprite.move(movement);
    }
}

void Unit::loadTexture()
{
    sprite.setTexture((*texture));
}

void Unit::setPlayerPosition()
{
    sprite.setPosition(((float)window->getSize().x - (float)texture->getSize().x) / 2, (float)window->getSize().y - (float)texture->getSize().y);
}

void Unit::setEnemyPosistion(float x, float y)
{
    sprite.setPosition(x, y);
}

void Unit::setSize(float size) {
    sprite.setScale(size, size);
}

void Unit::updateSprite()
{
    window->draw(sprite);
}

float Unit::getXCenter() const
{
    return sprite.getPosition().x + texture->getSize().x / 2;
}

float Unit::getY() const
{
    return sprite.getPosition().y;
}

float Unit::getDown() const
{
    return sprite.getPosition().y+texture->getSize().y;
}


Vector2f Unit::getCenter() const
{
    Vector2f a(texture->getSize().x/2,texture->getSize().y/2);
    return sprite.getPosition()+a;
}

Vector2<unsigned int>Unit::getBounds() const
{
    return texture->getSize();
}

float modulo(float a)
{
    if(a<0)
        return -a;
    return a;
}

bool Unit::collision(sf::Vector2f centerV, sf::Vector2<unsigned int>boundsV) const
{
    if(modulo(getCenter().x - centerV.x) < (texture->getSize().x + boundsV.x)/2.5 && modulo(getCenter().y - centerV.y) < (texture->getSize().y + boundsV.y)/2.5)
    {
        return true;
    }
    return false;
}

bool Unit::collision(sf::Vector2f centerV, float diameter) const
{
    if(modulo(getCenter().x - centerV.x) < (texture->getSize().x + diameter)/2 && modulo(getCenter().y - centerV.y) < (texture->getSize().y + diameter)/2)
    {
        return true;
    }
    return false;
}

bool Unit::killMe() const
{
    if(sprite.getPosition().y-window->getSize().y>0)
        return true;
    return false;
}