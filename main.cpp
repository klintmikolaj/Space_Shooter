#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Player.h"
//#include "Audio.h"
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
    Texture playerTexture;
    font.loadFromFile("../ethnocentricRg.otf");
    playerTexture.loadFromFile("../Starship.png");
    window.create(VideoMode(windowWidth, windowHeight), "Space shooter (name subject to change)");
    Menu menu(windowWidth, windowHeight, window);
    menu.menu_update();
    Player player(name, window, playerTexture);
    Game game(player, window, font);
    game.run();

    return 0;
}
