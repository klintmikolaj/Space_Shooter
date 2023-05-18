//
// Created by indianajones on 5/14/23.
//

#ifndef SPACE_SHOOTER_ALIEN_H
#define SPACE_SHOOTER_ALIEN_H
#include <SFML/Graphics.hpp>
#include "Unit.h"

class Alien: public Enemies {
public:
    Alien(sf::RenderWindow & windowArg, sf::Texture & textureArg, float x, float y, float size);
    void updateAlien();
private:
    sf::RenderWindow& window;
};


#endif //SPACE_SHOOTER_ALIEN_H
