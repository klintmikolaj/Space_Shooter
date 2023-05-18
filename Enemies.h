#ifndef SPACE_SHOOTER_ENEMIES_H
#define SPACE_SHOOTER_ENEMIES_H

#include <SFML/Graphics.hpp>
#include "Unit.h"

class Enemies: public Unit {
public:
    Enemies(sf::RenderWindow&, sf::Texture&, int);
    int getDamage() const;

protected:
    //int type; /* Zalozmy ze 1 - zwykla asteroida, 2 - statek niestrzelajacy, 3 - statek strzelajacy */
    int hpMax;
    float speed;
    int damage; /* jaki zadaje spritowi gracza */
};

#endif