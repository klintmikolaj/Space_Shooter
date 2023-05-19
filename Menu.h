#ifndef SPACE_SHOOTER_MENU_H
#define SPACE_SHOOTER_MENU_H

#include <SFML/Graphics.hpp>
#define MENU_ITEMS 5


class Menu {
public:
    Menu(float x, float y, sf::RenderWindow &, sf::Font &);
    void draw();
    int menu_update();
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