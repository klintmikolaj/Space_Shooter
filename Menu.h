#ifndef SPACE_SHOOTER_MENU_H
#define SPACE_SHOOTER_MENU_H

#include <SFML/Graphics.hpp>
#include "Audio.h"
#define MENU_ITEMS 6

class Menu {
public:
    Menu(sf::RenderWindow &, sf::Font &);
    void draw();
    short menu_update();
    void Move_Up();
    void Move_Down();
    void Load_background();
    void Draw_background();
    void musicLoad();
private:
    sf::RenderWindow &window;
    int Selected_index;
    Audio audio;
    sf::Font & font;
    sf::Text menu[MENU_ITEMS];
    sf::Texture backgroundTexture;
    sf::Sprite background;
};

#endif