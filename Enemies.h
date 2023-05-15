#ifndef SPACE_SHOOTER_ASTEROID_H
#define SPACE_SHOOTER_ASTEROID_H

#include <SFML/Graphics.hpp>
#include "Unit.h"

class Enemies: public Unit {
public:
    Enemies(sf::RenderWindow&, sf::Texture&, int);
    int getDamage() const;

private:
    int type; /* Zalozmy ze 1 - zwykla asteroida, 2 - statek niestrzelajacy, 3 - statek strzelajacy */
    int hpMAX;
    float speed;
    sf::Texture asteroid_Texture;
    sf::Sprite asteroid_Sprite;
};

#endif