#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Game.h"
#include <iostream>

using namespace std;

Game::Game(Player& playerArg, sf::RenderWindow & windowArg, sf::Font& fontArg): player(playerArg), window(windowArg), font(fontArg)
{
    bulletTexture.loadFromFile("../bullet.png");
    asteroidTexture1.loadFromFile("../as21.png");
    asteroidTexture2.loadFromFile("../asteroid2.png");
    alienTexture1.loadFromFile("../Starship_3.png");
}

void Game::run()
{
    window.clear(sf::Color::Black);
    asteroidsSetSpawners();
    aliensSetSpawners();
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
    asteroidAhead();
    alienAttack();
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
                        player.moveX(10,true);
                        break;
                    case sf::Keyboard::Left:
                        player.moveX(10,false);
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
    bulletsBank.push_back(new Shoot(window,bulletTexture,playerArg,up));
}

void Game::masterOfBullets()
{
    unsigned int ii=0;
//    for(vector<Shoot>::iterator a=bulletsBank.begin();a!=bulletsBank.end();++a)
    for(auto *a:bulletsBank)
    {
        a->updateBullet();
        // a->destroyMe();
        if (a->destroyMeBool())
        {
            bulletsBank.erase(bulletsBank.begin()+ii);
//            //destroy bullet, i don't know how at this moment...
//            bulletsBank.erase(a);
//            //delete a;
        }
        ++ii;
    }
}


void Game::asteroidAhead() {
    asteroidSpawnNow += 0.05;
//    if (spawnNow >= spawnCooldown) {
//        asteroids.push_back(new Asteroid(window, asteroidTexture1, rand() % window.getSize().x - 45, -100,
//                                         1));
//        spawnNow = 0;
//    }
    if (asteroidSpawnNow >= asteroidSpawnCooldown) {
        asteroids.push_back(new Asteroid(window, asteroidTexture2, rand() % window.getSize().x - 45, -100,
                                         1));
        asteroidSpawnNow = 0;
    }
    for (auto Asteroid: asteroids) {
        Asteroid->updateAsteroid();
//        std::cout<<Asteroid->getXCenter()<<";"<<Asteroid->getY()<<"\t";
    }
}

void Game::alienAttack() {
    alienSpawnNow += 0.05;
    if (alienSpawnNow >= alienSpawnCooldown) {
        aliens.push_back(new Alien(window, alienTexture1, rand() % window.getSize().x - 20, -120,
                                         1));
        alienSpawnNow = 0;
    }
    for (auto Alien: aliens) {
        Alien->updateAlien();
        std::cout<<Alien->getXCenter()<<";"<<Alien->getY()<<"\t";
    }
}

void Game::asteroidsSetSpawners()
{
    this->asteroidSpawnCooldown = 100;
    this->asteroidSpawnNow = this->asteroidSpawnCooldown;
}

void Game::aliensSetSpawners()
{
    this->alienSpawnCooldown = 200;
    this->alienSpawnNow = this->alienSpawnCooldown;
}



float Game::setNumberRange(int max, int min) {
    return (rand() % ((max - min + 1) + min)) - 0.1;
}


//void Game::setBackground() {
//    window.draw()
//}
