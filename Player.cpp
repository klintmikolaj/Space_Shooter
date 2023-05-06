//
// Created by indianajones on 4/29/23.
//

#include <SFML/Graphics.hpp>
#include <string>
#include "Player.h"
#include <iostream>

using namespace std;
using namespace sf;

Player::Player(string& namearg, RenderWindow & windowarg): Player{namearg, windowarg, 3}
{
}

Player::Player(string& namearg, RenderWindow & windowarg, int hparg):name(namearg), window{windowarg}, hp(hparg)
{
}

void Player::move(bool direction)
{
    int px;
    bool visible;
    if(direction)
    {
        px = 20;
        visible=window.getSize().x-playerSprite.getPosition().x-px-playerTexture.getSize().x>0;
    }
    else
    {
        px = -20;
        visible=(playerSprite.getPosition().x+px)>=0;
    }
    if(visible)
        playerSprite.setPosition(playerSprite.getPosition().x+px,playerSprite.getPosition().y);
    showSprite();
}

void Player::loadTexture()
{
    Sprite sprite;
    playerTexture.loadFromFile("../Starship_4.png");
    playerTexture.setSmooth(true);
    playerSprite.setTexture(playerTexture);
    playerSprite.scale(0.1f, 0.1f);
    playerSprite.setPosition(250,300);


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
