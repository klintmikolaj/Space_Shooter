#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
//#include <SFML/>
#include "Audio.h"
#include "Player.h"

using namespace std;

int main()
{
    string name="adam";
    sf::RenderWindow window;
    window.create(sf::VideoMode(800, 600), "Space shooter (name subject to change)");
    Player player(name, window);
    Game game(player, window);
    game.run();

    return 0;
}
