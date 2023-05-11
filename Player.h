//
// Created by indianajones on 4/29/23.
//

#ifndef SPACE_SHOOTER_PLAYER_H
#define SPACE_SHOOTER_PLAYER_H

#include "Unit.h"

class Player: public Unit
{
    public:
        Player(std::string & playerName, sf::RenderWindow & windowArg, sf::Texture & textureArg);

        std::string getName() const;

    private:
        const std::string name;
};


#endif //SPACE_SHOOTER_PLAYER_H
