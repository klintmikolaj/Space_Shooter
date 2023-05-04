#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Game.h"
#include <iostream>

using namespace std;

Game::Game(Player& playerarg, sf::RenderWindow & windowarg): player(playerarg), window(windowarg)
{
    font.loadFromFile("../ethnocentricRg.otf");
}

void Game::run()
{
    window.clear(sf::Color::Black);
    playerStats.setFont(font);
    playerStats.setFillColor(sf::Color::Blue);
    playerStats.setCharacterSize(40);
    string playerStatsStr=player.getName();
    playerStatsStr+="    HP ";
    playerStatsStr+= to_string(player.getHP());
    playerStats.setString(playerStatsStr);
    playerStats.setPosition(200,0);
    player.loadTexture();
    player.showSprite();
    //audio.bgMusicLoad();
    //audio.bgMusicPlay();
    while(window.isOpen())
    {
        update();
        display();
    }
}

void Game::update()
{
    window.clear(sf::Color::Black);
    while (window.pollEvent(event))
    {
        switch(event.type)
        {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                switch(event.key.code)
                {
                    case sf::Keyboard::Escape:
                        window.close();
                        break;
                    case sf::Keyboard::Right:
                        player.move(true);
                        break;
                    case sf::Keyboard::Left:
                        player.move(false);
                        break;
                    default:
                        break;
                }
            default:
                break;
        }
    }
    window.draw(playerStats);
    player.showSprite();
    window.display();
}

void Game::display()
{
}
