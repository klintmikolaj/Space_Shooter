//
// Created by indianajones on 5/14/23.
//

#ifndef SPACE_SHOOTER_ALIEN_H
#define SPACE_SHOOTER_ALIEN_H
#include <SFML/Graphics.hpp>
#include "Enemies.h"

class Alien: public Enemies {
public:
    Alien(sf::RenderWindow * windowArg, sf::Texture * textureArg, float x, float y, float size, int pointsForPlayerArg, float speedArg);

    /*
     * making the alien do a transformed periodical movement
     * updating the alien
    */
    void update();
protected:
    int tick;
};


#endif //SPACE_SHOOTER_ALIEN_H
