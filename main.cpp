#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Player.h"
//#include "Audio.h"
#include "Menu.h"
#include "Asteroid.h"

using namespace std;
using namespace sf;

int main()
{
    const int windowWidth=1000;
    const int windowHeight=800;
    string name="adam";
    RenderWindow window;
    Font font;
    Texture playerTexture, asteroidTexture;
    font.loadFromFile("../ethnocentricRg.otf");
    playerTexture.loadFromFile("../Starship.png");
    asteroidTexture.loadFromFile("../as2");
    window.create(VideoMode(windowWidth, windowHeight), "Space shooter (name subject to change)");
    Menu menu(windowWidth, windowHeight, window, font);
    menu.menu_update();
    Asteroid asteroid(window, asteroidTexture);
    Player player(name, window, playerTexture);
    Game game(player, asteroid, window, font);
    game.run();

    return 0;
}
