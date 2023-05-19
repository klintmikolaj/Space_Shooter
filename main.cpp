#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Menu.h"

using namespace std;
using namespace sf;

int main()
{
    const int windowWidth=1000;
    const int windowHeight=800;
    string name="adam";
    RenderWindow window;
    Font font;
    font.loadFromFile("../fonts/ethnocentricRg.otf");
    window.create(VideoMode(windowWidth, windowHeight), "Space shooter (name subject to change)");
    Menu menu(windowWidth, windowHeight, window, font);
    menu.menu_update();
    Game game(name, window, font);
    game.run();

    return 0;
}
