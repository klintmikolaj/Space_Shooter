#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Game.h"
#include <iostream>

using namespace std;

Game::Game(Player& playerArg, sf::RenderWindow & windowArg, sf::Font& fontArg): player(playerArg), window(windowArg), font(fontArg)
{
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
//        menu.draw(window);
        display();

    }
}

void Game::update()
{
    window.clear(sf::Color::Black);
    while (window.pollEvent(event))
    {
        bool isSkip=false;
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
                    case sf::Keyboard::LShift:
                    case sf::Keyboard::RShift:
                        isSkip=true;
                        break;
                    case sf::Keyboard::Right:
                        player.move(true,isSkip);
                        break;
                    case sf::Keyboard::Left:
                        player.move(false,isSkip);
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
