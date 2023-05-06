#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Player.h"

using namespace std;

int main()
{
    const int windowWidth=1000;
    const int windowHeight=800;
    string name="adam";
    sf::RenderWindow window;
    sf::Font font;
    font.loadFromFile("../ethnocentricRg.otf");
    window.create(sf::VideoMode(windowWidth, windowHeight), "Space shooter (name subject to change)");
    Player player(name, window);
    Game game(player, window, font);
    game.run();

    return 0;
}
