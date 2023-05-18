#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Game.h"
#include <iostream>

using namespace std;
using namespace sf;

Game::Game(Player& playerArg, sf::RenderWindow & windowArg, sf::Font& fontArg): player(playerArg), window(windowArg), font(fontArg), isSkip(false), isLeft(false), isX(false), isUp(false), isY(false)
{
    lastEnemy=NULL;
}

void Game::run()
{
    //frameCount = 0;
    window.clear(sf::Color::Black);
    loadTextures();
    background.setTexture(backgroundTexture);
    window.draw(background);
    loadPlayerStats();
    asteroidsSetSpawners();
    aliensSetSpawners();
    player.loadTexture();
    player.showSprite();
    //audio.bgMusicLoad();
    //audio.bgMusicPlay();
    while(window.isOpen()) {
        update();
        display();
    }
}

void Game::update()
{
    window.clear(sf::Color::Black);
    window.draw(background);
    masterOfBullets();
    playerManager();
    asteroidAhead();
    alienAttack();
    drawPlayerStuff();
    drawInterface();
    steer();
    window.display();
   // frameCount += 1;
}

void Game::display()
{
}

void Game::steer()
{
    while (window.pollEvent(event))
//    {
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
                    case sf::Keyboard::Left:
                        isLeft=true;
                    case sf::Keyboard::Right:
                        isX=true;
                        break;
                    case sf::Keyboard::Up:
                        isUp=true;
                    case sf::Keyboard::Down:
                        isY=true;
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
                    case sf::Keyboard::Left:
                        isLeft=false;
                    case sf::Keyboard::Right:
                        isX=false;
                        break;
                    case sf::Keyboard::Up:
                        isUp=false;
                    case sf::Keyboard::Down:
                        isY=false;
                        break;
                    default:
                        break;
                }
            default:
                break;
        }
//    }
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
    backColour.a=128;
    backColour.r=100;
    backColour.g=100;
    backColour.b=100;
    statsBackground.setSize(sf::Vector2f(window.getSize().x, 60));
    statsBackground.setPosition(0,0);
    statsBackground.setFillColor(backColour);
    window.draw(statsBackground);
    statsUpdate();
    window.draw(playerStats);
}

void Game::drawPlayerStuff()
{
    player.showSprite();
}

void Game::loadTextures() {
    backgroundTexture.loadFromFile("../background2.jpg");
//    bulletTexture.loadFromFile("../bullet_smol.png");
    bulletTexture.loadFromFile("../New_Bullet.png");
    asteroidTexture1.loadFromFile("../as21.png");
    asteroidTexture2.loadFromFile("../asteroid2.png");
    alienTexture1.loadFromFile("../Starship_3.png");
}

void Game::loadPlayerStats() {
    playerStats.setFont(font);
    playerStats.setFillColor(sf::Color::Blue);
    playerStats.setCharacterSize(40);
    string playerStatsStr=player.getName();
    playerStatsStr+="    HP ";
    playerStatsStr+= to_string(player.getHP());
    playerStats.setString(playerStatsStr);
    playerStats.setPosition(300,0);
}

void Game::playerManager()
{
    for(auto as:asteroids)
    {
        if(as != lastEnemy)
            if(player.collision(as->getCenter(),as->getBounds()))
            {
                lastEnemy=as;
                player.decreaseHP();
            }
    }
    for(auto al:aliens)
    {
        if(al != lastEnemy)
            if(player.collision(al->getCenter(),al->getBounds()))
            {
                lastEnemy=al;
                player.decreaseHP();
            }
    }
    if(isX)
    {
        if (isSkip)
            player.moveX(0.4, !isLeft);
        player.moveX(0.1, !isLeft);
    }
    if(isY)
    {
        if (isSkip)
            player.moveY(0.4, !isUp);
        player.moveY(0.1, !isUp);
    }
    if(player.isDead())
        window.close() ;
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
    asteroidSpawnNow += 0.1;
    if (asteroidSpawnNow >= asteroidSpawnCooldown) {
        asteroids.push_back(new Asteroid(window, asteroidTexture2, rand() % window.getSize().x - 45, -100,1));
        asteroidSpawnNow = 0;

    }
    unsigned int ii=0;
    for (auto Asteroid: asteroids) {
        Asteroid->updateAsteroid();
        if(Asteroid->killMe())
            asteroids.erase(asteroids.begin()+ii);

        unsigned int bii=0;
        for(auto a:bulletsBank)
        {
            if(Asteroid->collision(a->getCenter(), a->getDiameter()))
            {
                asteroids.erase(asteroids.begin()+ii);
                bulletsBank.erase(bulletsBank.begin()+bii);
            }
            ++bii;
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
            if(Alien->collision(a->getCenter(), a->getDiameter()))
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
    asteroidSpawnCooldown = 100 ;
    asteroidSpawnNow = asteroidSpawnCooldown;
}

void Game::aliensSetSpawners()
{
    alienSpawnCooldown = 100;
    alienSpawnNow = alienSpawnCooldown;
}

void Game::setBackground()
{

}



float Game::setNumberRange(int max, int min) {
    return (rand() % ((max - min + 1) + min)) - 0.1;
}

