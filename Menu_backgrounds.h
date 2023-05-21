//
// Created by indianajones on 5/21/23.
//

#ifndef SPACE_SHOOTER_MENU_BACKGROUNDS_H
#define SPACE_SHOOTER_MENU_BACKGROUNDS_H
#include <SFML/Graphics.hpp>

class Menu_backgrounds {
public:
    Menu_backgrounds(float x, float y, sf::RenderWindow &window);
    void setBackgroundTexture();
    void drawCredits();
    void drawHowToPlay();
private:
    sf::RenderWindow &window;
    sf::Texture creditsTexture;
    sf::Texture howToPlayTexture;
    sf::Sprite credits;
    sf::Sprite howToPlay;
};


#endif //SPACE_SHOOTER_MENU_BACKGROUNDS_H
