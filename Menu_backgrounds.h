//
// Created by indianajones on 5/21/23.
//

#ifndef SPACE_SHOOTER_MENU_BACKGROUNDS_H
#define SPACE_SHOOTER_MENU_BACKGROUNDS_H
#include <SFML/Graphics.hpp>
#include "Audio.h"

class Menu_backgrounds {
public:
    Menu_backgrounds(sf::RenderWindow &window);
    void setBackgroundTexture();
    void draw(bool credits);
private:
    Audio audio;
    sf::RenderWindow &window;
    sf::Texture creditsTexture;
    sf::Texture howToPlayTexture;
    sf::Sprite bg;
};


#endif //SPACE_SHOOTER_MENU_BACKGROUNDS_H
