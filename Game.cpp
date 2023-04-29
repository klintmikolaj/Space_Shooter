#include <SFML/Graphics.hpp>
#include "Game.h"
#include <SFML/Window.hpp>
Game::Game() {

}

void Game::run() {
    window.create(sf::VideoMode(800, 600), "My window");
    while(window.isOpen())
    {
        update();
        display();
    }
}

void Game::update() {
    window.clear(sf::Color::Black);
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Game::display() {
    window.display();
}
