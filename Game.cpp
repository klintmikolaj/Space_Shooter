#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Game.h"
#include <iostream>

using namespace std;

Game::Game(Player& playerArg, sf::RenderWindow & windowArg, sf::Font& fontArg): player(playerArg), window(windowArg), font(fontArg), isSkip(false)
{
    bulletTexture.loadFromFile("../bullet_smol.png");
    asteroidTexture1.loadFromFile("../as21.png");
    asteroidTexture2.loadFromFile("../asteroid2.png");
    alienTexture1.loadFromFile("../Starship_3.png");
    backColour.a=128;
    backColour.r=100;
    backColour.g=100;
    backColour.b=100;
    statsBackground.setSize(sf::Vector2f(400, 60));
    statsBackground.setPosition(280,0);
    statsBackground.setFillColor(backColour);
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
    playerStats.setPosition(300,0);
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
    masterOfBullets();
    playerManager();
    asteroidAhead();
    alienAttack();
    drawPlayerStuff();
    drawInterface();
    steer();
    window.display();
}

void Game::display()
{
}

void Game::steer()
{
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
                        //cout<<"przycisk\t";
                        break;
                    case sf::Keyboard::Right:
                        if(isSkip)
                            player.moveX(60,true);
                        player.moveX(10,true);
                        break;
                    case sf::Keyboard::Left:
                        if(isSkip)
                            player.moveX(60,false);
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
                        //cout<<"puszczenie\t";
                        break;
                    default:
                        break;
                }
            default:
                break;
        }
    }
}


void Game::statsUpdate()
{
    string playerStatsStr=player.getName();
    playerStatsStr+="    HP ";
    playerStatsStr+= to_string(player.getHP());
    playerStats.setString(playerStatsStr);
}

void Game::drawInterface()
{
    window.draw(statsBackground);
    statsUpdate();
    window.draw(playerStats);
}

void Game::drawPlayerStuff()
{
    player.showSprite();
}

void Game::playerManager()
{
    for(auto as:asteroids)
    {
        if(player.collision(as->center()))
            player.decreaseHP();
    }
    for(auto al:aliens)
    {
        if(player.collision(al->center()))
            player.decreaseHP();
    }
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
        if (a->destroyMe())
        {
            bulletsBank.erase(bulletsBank.begin()+ii);
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
        asteroids.push_back(new Asteroid(window, asteroidTexture2, rand() % window.getSize().x - 45, -100,1));
        asteroidSpawnNow = 0;
    }
    unsigned int ii=0;
    for (auto Asteroid: asteroids) {
        Asteroid->updateAsteroid();
        if(Asteroid->killMe())
            asteroids.erase(asteroids.begin()+ii);
        for(auto a:bulletsBank)
        {
            if(Asteroid->collision(a->getCenter()))
                asteroids.erase(asteroids.begin()+ii);
        }
        ++ii;
//        std::cout<<"As"<<ii<<":"<<Asteroid->getXCenter()<<";"<<Asteroid->getY()<<"\n";
    }
}

void Game::alienAttack() {
    alienSpawnNow += 0.05;
    if (alienSpawnNow >= alienSpawnCooldown) {
        aliens.push_back(new Alien(window, alienTexture1, rand() % window.getSize().x - 20, -120,1));
        alienSpawnNow = 0;
    }
    unsigned int ii=0;
    for (auto Alien: aliens) {
        Alien->updateAlien();
        if(Alien->killMe())
            aliens.erase(aliens.begin()+ii);
        unsigned int bii=0;
        for(auto a:bulletsBank)
        {
            if(Alien->collision(a->getCenter()))
            {
                aliens.erase(aliens.begin() + ii);
                bulletsBank.erase(bulletsBank.begin()+bii);
            }
            ++bii;
        }
        ++ii;
//        std::cout<<"Al"<<ii<<":"<<Alien->getXCenter()<<";"<<Alien->getY()<<"\n";
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
