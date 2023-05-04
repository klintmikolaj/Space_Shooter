//
// Created by indianajones on 4/29/23.
//

#include <SFML/Graphics.hpp>
#include <string>
#include "Player.h"
#include <iostream>

using namespace std;

Player::Player(string& namearg, sf::RenderWindow & windowarg): Player{namearg, windowarg, 3}
{
}

Player::Player(string& namearg, sf::RenderWindow & windowarg, int hparg):name(namearg), window{windowarg}, hp(hparg)
{
}

void Player::move(bool direction)
{
    int px;
    bool visible;
    if(direction)
    {
        px = 10;
        visible=window.getSize().x-playerSprite.getPosition().x-px-playerTexture.getSize().x>0;
    }
    else
    {
        px = -10;
        visible=(playerSprite.getPosition().x+px)>=0;
    }
    if(visible)
        playerSprite.setPosition(playerSprite.getPosition().x+px,playerSprite.getPosition().y);
    showSprite();
}

void Player::loadTexture()
{
    playerTexture.loadFromFile("../poppy.png");
    playerSprite.setTexture(playerTexture);
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
