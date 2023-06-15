#ifndef SPACE_SHOOTER_MENU_H
#define SPACE_SHOOTER_MENU_H

#include <SFML/Graphics.hpp>
#include "Audio.h"
#define MENU_ITEMS 6

class Menu {
public:
    Menu(sf::RenderWindow &, sf::Font &);

    /*
     * Loading and drawing background
     * Clearing all previous objects and drawing new menu
     */
    void draw();

    /*
     * Updating menu
     */
    short menu_update();

    /*
     * Both functions let the player maneuver in menu
     * Press up arrow to go up
     * Press down arrow to go down
     */
    void Move_Up();
    void Move_Down();

    /*
     * Loading menu backgrund from file
     */
    void Load_background();

    /*
     * Displaying imported background
     */
    void Draw_background();

    /*
     * Adding music
     */
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