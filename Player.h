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

        /*
        * @param amount
         * Functions adds amount of points received by killing an alien
        */
        void increasePoints(int amount);

        /*
        * Decreasing players HP
        */
        void decreaseHP();

        /*
        * Function returns the number of HP points in current time
        */
        int getHP() const;

        std::string getName() const;

        /*
        * Function returns the number of player points
        */
        int getPoints() const;

        /*
        * Function checks if player has lost all Hp points
        */
        bool isDead() const;

    private:
        const std::string name;
        int hp;
        long points;
};


#endif //SPACE_SHOOTER_PLAYER_H
