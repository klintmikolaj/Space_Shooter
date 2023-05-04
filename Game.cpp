#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Game.h"
#include <iostream>
#include "Menu.h"

using namespace std;
using namespace sf;

Game::Game(Player& playerarg, RenderWindow & windowarg): player(playerarg), window(windowarg)
{
    font.loadFromFile("../ethnocentricRg.otf");
}

void Game::run()
{
    window.clear(Color::Black);
    playerStats.setFont(font);
    playerStats.setFillColor(Color::Blue);
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
    window.clear(Color::Black);
    while (window.pollEvent(event))
    {
        switch(event.type)
        {
            case Event::Closed:
                window.close();
                break;
            case Event::KeyPressed:
                switch(event.key.code)
                {
                    case Keyboard::Escape:
                        window.close();
                        break;
                    case Keyboard::Right:
                        player.move(true);
                        break;
                    case Keyboard::Left:
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
