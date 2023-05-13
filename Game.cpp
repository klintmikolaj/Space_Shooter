#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Game.h"
#include <iostream>

using namespace std;

Game::Game(Player& playerArg, sf::RenderWindow & windowArg, sf::Font& fontArg): player(playerArg), window(windowArg), font(fontArg)
{
    bulletTexture.loadFromFile("../bullet.png");
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
    drawPlayerStuff();
    drawInterface();
    masterOfBullets();
    steer();
    window.display();
}

void Game::display()
{
}

void Game::steer()
{
    bool isSkip=false;

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
                    case sf::Keyboard::LShift:
                    case sf::Keyboard::RShift:
                        isSkip=true;
                        cout<<"przycisk\t";
                        break;
                    case sf::Keyboard::Right:
                        player.moveX(true, isSkip);
                        break;
                    case sf::Keyboard::Left:
                        player.moveX(false, isSkip);
                        break;
                    case sf::Keyboard::Space:
                        bulletMaker(player,true);
                        break;
                    default:
                        break;
                }
                break;
            case sf::Event::KeyReleased:
                switch(event.key.code)
                {
                    case sf::Keyboard::LShift:
                    case sf::Keyboard::RShift:
                        isSkip=false;
                        cout<<"puszczenie\t";
                        break;
                    default:
                        break;
                }
            default:
                break;
        }
    }
}

void Game::drawInterface()
{
    window.draw(playerStats);
}

void Game::drawPlayerStuff()
{
    player.showSprite();
}

void Game::bulletMaker(Player& playerArg, bool up)
{
    bulletsBank.emplace_back(window,bulletTexture,playerArg,up);
}

void Game::masterOfBullets()
{
    for(vector<Shoot>::iterator a=bulletsBank.begin();a!=bulletsBank.end();++a)
    //for(auto &a:bulletsBank)
    {
        a->updateBullet();
        // a->destroyMe();
//        if (a->destroyMeBool())
//        {
//            //destroy bullet, i don't know how at this moment...
//            bulletsBank.erase(a);
//            //delete a;
//        }
    }
}