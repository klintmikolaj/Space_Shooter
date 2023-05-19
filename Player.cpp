//
// Created by indianajones on 4/29/23.
//

#include <SFML/Graphics.hpp>
#include <string>
#include "Player.h"

using namespace std;
using namespace sf;

Player::Player(string& playerName, RenderWindow & windowArg, Texture & textureArg): Unit{windowArg, textureArg}, name(playerName), points(0), hp(3)
{
    setPlayerPosition();
}

void Player::increasePoints(int amount)
{
    points+=amount;
}

void Player::decreaseHP()
{
    if(hp>0)
        hp--;
}

int Player::getHP() const
{
    return hp;
}

string Player::getName() const
{
    return name;
}

int Player::getPoints() const
{
    return points;
}

bool Player::isDead() const
{
    if(hp>0)
        return false;
    return true;
}