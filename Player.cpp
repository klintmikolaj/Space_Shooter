//
// Created by indianajones on 4/29/23.
//

#include <SFML/Graphics.hpp>
#include <string>
#include "Player.h"

using namespace std;
using namespace sf;

Player::Player(string& playerName, RenderWindow & windowArg, Texture & textureArg): Unit{windowArg, textureArg}, name(playerName)
{
    setPlayerPosition();
}

string Player::getName() const
{
    return name;
}