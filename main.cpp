#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Audio.h"
#include "Menu.h"

using namespace std;
using namespace sf;

int main()
{
    string name="adam";
    RenderWindow window;
    window.create(VideoMode(1000, 800), "Space shooter (name subject to change)");
    Menu menu(window.getSize().x, window.getSize().y, window);
    menu.menu_update();
    Player player(name, window);
    Game game(player, window);
    game.run();

    return 0;
}
