#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Menu.h"
#include "Settings.h"

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
    Menu menu{windowWidth, windowHeight, window, font};
    short difficulty=1;
    short temp=10;
    while(temp>1)
    {
        temp=menu.menu_update();
        if(temp==2)
        {
            Settings settings(windowWidth, windowHeight, window, font);
            difficulty = static_cast<short>(settings.settingsUpdate());
        }
    }
    Game game(name, window, font, difficulty);
    game.run();

    return 0;
}
