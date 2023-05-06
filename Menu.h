#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
#define MENU_ITEMS 5
using namespace std;
using namespace sf;

class Menu {
public:
    Menu(float x, float y, RenderWindow &);
//    void draw(RenderWindow &window);
    void draw();
    int menu_update();
    void Move_Up();
    void Move_Down();
private:
    RenderWindow &window;
    int Selected_index;
    Font font;
    Text menu[MENU_ITEMS];
};

