#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
#define MAX_NUMBER_OF_ITEMS 4
using namespace std;
using namespace sf;

class Menu {
public:
    Menu(float x, float y);
    void draw(RenderWindow &window);
    void Move_Up();
    void Move_Down();
private:
    int Selected_index;
    Font font;
    Text menu[MAX_NUMBER_OF_ITEMS];

};

