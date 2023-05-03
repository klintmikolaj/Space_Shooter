#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Game.h"
#include "Menu.h"

Game::Game() {

}

void Game::run() {
    window.create(sf::VideoMode(1000, 800), "My window");
    Menu menu(window.getSize().x, window.getSize().y);
    while(window.isOpen())
    {

        update();
        menu.draw(window);
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
