//
// Created by indianajones on 4/29/23.
//

#include <SFML/Graphics.hpp>
#include <string>
#include "Player.h"

using namespace std;
using namespace sf;

Player::Player(string& nameArg, RenderWindow & windowArg): Player{nameArg, windowArg, 3}
{
}

Player::Player(string& nameArg, RenderWindow & windowArg, int hpArg):name(nameArg), window{windowArg}, hp(hpArg)
{
}

void Player::move(bool direction, bool isSkip)
{
    char px=20;
    if(isSkip)
        px*=5;
    bool visible;
    if(direction)
    {
        visible=window.getSize().x-playerSprite.getPosition().x-px-playerTexture.getSize().x/2>0;
    }
    else
    {
        px=(char)-px;
        visible=(playerSprite.getPosition().x+playerTexture.getSize().x/2+px)>=0;
    }
    if(visible)
        playerSprite.move(px,0);
    showSprite();
}

void Player::loadTexture()
{
    playerTexture.loadFromFile("../Starship.png");
    playerTexture.setSmooth(true);
    playerSprite.setTexture(playerTexture);
    playerSprite.setPosition(((float)window.getSize().x-(float)playerTexture.getSize().x)/2,(float)window.getSize().y-(float)playerTexture.getSize().y);
}

void Player::showSprite()
{
    window.draw(playerSprite);
}

int Player::getHP() const
{
    return hp;
}

string Player::getName() const
{
    return name;
}

float Player::getXLeft() const
{
    return playerSprite.getPosition().x;
}

float Player::getXCenter() const
{
    return playerSprite.getPosition().x+playerTexture.getSize().x/2;
}

float Player::getY() const
{
    return playerSprite.getPosition().y;
}