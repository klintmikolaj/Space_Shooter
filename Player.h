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

        void increasePoints(int amount);
        void decreaseHP();

        int getHP() const;
        std::string getName() const;
        int getPoints() const;
        bool isDead() const;

    private:
        const std::string name;
        int hp;
        long points;
};


#endif //SPACE_SHOOTER_PLAYER_H
