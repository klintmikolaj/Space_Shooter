#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Game.h"

using namespace std;
using namespace sf;

//#define greater(x, y) ((x) > (y) ? (x) : (y))

Game::Game(sf::RenderWindow & windowArg, sf::Font& fontArg, short& difficultyArg): player{windowArg,playerTexture}, window(windowArg), font(fontArg), multiplier(1), difficulty(difficultyArg), isLeft(false), isX(false), isUp(false), isY(false)
{
    lastBullet=nullptr;
}

void Game::loadTextures()
{
    playerTexture.loadFromFile("../textures/Starship_smol.png");
    backgroundTexture.loadFromFile("../textures/background2.jpg");
    bulletTexture.loadFromFile("../textures/New_Bullet.png");
    alienBulletTexture.loadFromFile("../textures/New_Bullet_Red.png");
    asteroidTexture2.loadFromFile("../textures/asteroid2.png");
    alienTexture1.loadFromFile("../textures/Starship_3.png");
    shootingAlienTexture.loadFromFile("../textures/Starship_4_smol.png");
}

void Game::loadPlayerStats()
{
    playerStats.setFont(font);
    playerStats.setFillColor(sf::Color::Cyan);
    playerStats.setCharacterSize(40);
}

void Game::setSpawners()
{
    asteroidSpawnCooldown = 200 ;
    asteroidSpawnNow = asteroidSpawnCooldown;
    alienSpawnCooldown = 500;
    alienSpawnNow = alienSpawnCooldown;
    shootingAlienSpawnNow = alienSpawnCooldown;
    shootingNow = alienSpawnCooldown;
}

void Game::run()
{
    loadTextures();
    window.clear(sf::Color::Black);
    background.setTexture(backgroundTexture);
    window.draw(background);
    loadPlayerStats();
    setSpawners();
    player.loadTexture();
    player.setPlayerPosition();
    player.updateSprite();
    audio.bgMusicLoad(false);
    audio.bgMusicPlay();
    while(window.isOpen()&&update()){}
    if(!update())
    {
        gameOver();
    }
}

bool Game::steer()
{
    while (window.pollEvent(event))
//    {
        switch(event.type)
        {
            case sf::Event::Closed:
                return false;
                break;
            case sf::Event::KeyPressed:
                switch(event.key.code)
                {
                    case sf::Keyboard::Escape:
                        return false;
                        break;
                    case sf::Keyboard::LShift:
                    case sf::Keyboard::RShift:
                        multiplier=4;
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
                        createPlayerBullet(player);
                        audio.piu(true);
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
                        multiplier=1;
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
    return true;
}



template <typename SS>
void Game::playerCollision(SS& unitBank)
{
    for(auto as:unitBank)
    {
        if(&as != lastEnemy)
            if(player.collision(as.getCenter(),as.getBounds()))
            {
                audio.ough();
                lastEnemy=&as;
                player.decreaseHP();
            }
    }
}

void Game::playerCollision(std::vector<Shoot>& bulletBank)
{
    for(auto b:bulletBank)
    {
        if(&b != lastBullet)
            if(player.collision(b.getCenter(), b.getDiameter()))
            {
                lastBullet=&b;
                audio.ough();
                player.decreaseHP();
            }
    }
}


void Game::createPlayerBullet(Player& playerArg)
{
    bulletsBank.push_back(Shoot{&window,&bulletTexture,playerArg.getXCenter(),playerArg.getY(),true});
}

void Game::createAlienBullet(ShootingAlien & enemyArg)
{
    alienBulletsBank.push_back(Shoot{&window,&alienBulletTexture,enemyArg.getXCenter(),enemyArg.getDown(),false});
}

void Game::eraseBullet(Shoot& a, unsigned int& ii)
{
    if (a.destroyMe())
    {
        bulletsBank.erase(bulletsBank.begin()+ii);
    }
}



void Game::updateBullets()
{
    unsigned int ii=0;
    for(auto &a:bulletsBank)
    {
        a.updateBullet();
        eraseBullet(a, ii);
        ++ii;
    }
    for(auto &a:alienBulletsBank)
    {
        a.updateBullet();
        eraseBullet(a, ii);
        ++ii;
    }
}


bool Game::updatePlayer()
{
    playerCollision(aliens);
    playerCollision(shootingAliens);
    playerCollision(asteroids);
    playerCollision(alienBulletsBank);

    player.move(0.1*multiplier*isX,0.1*multiplier*isY,!isLeft,!isUp,false);

    player.updateSprite();

    if(player.isDead())
        return false;
    return true;
}


void Game::updateAsteroids()
{
    asteroidSpawnNow += 0.1;
    if (asteroidSpawnNow >= asteroidSpawnCooldown) {
        asteroids.push_back(Asteroid{&window, &asteroidTexture2, static_cast<float>(rand()% (window.getSize().x - asteroidTexture2.getSize().x)), static_cast<float>(-100),1,static_cast<float>(difficulty)});
        asteroidSpawnNow = 0;

    }
    unsigned int ii=0;
    for (auto &Asteroid: asteroids) {
        Asteroid.update();
        if(Asteroid.killMe())
            asteroids.erase(asteroids.begin()+ii);

        unsigned int bii=0;
        for(auto &a:bulletsBank)
        {
            if(Asteroid.collision(a.getCenter(), a.getDiameter()))
            {
                asteroids.erase(asteroids.begin()+ii);
                bulletsBank.erase(bulletsBank.begin()+bii);
                player.increasePoints(difficulty*Asteroid.getPoints());
            }
            ++bii;
        }
        ++ii;
    }
}

void Game::updateAliens()
{
    alienSpawnNow += 0.05;
    if (alienSpawnNow >= alienSpawnCooldown)
    {
        aliens.push_back(Alien{&window, &alienTexture1, static_cast<float>(rand() % (window.getSize().x - alienTexture1.getSize().x)), static_cast<float>(-120),1,5,2*static_cast<float>(difficulty)});
        alienSpawnNow = 0;
    }
    unsigned int ii=0;
    for (auto &Alien: aliens)
    {
        Alien.update();
        if(Alien.killMe())
            aliens.erase(aliens.begin()+ii);

        unsigned int bii=0;
        for(auto &a:bulletsBank)
        {
            if(Alien.collision(a.getCenter(), a.getDiameter()))
            {
                aliens.erase(aliens.begin() + ii);
                bulletsBank.erase(bulletsBank.begin()+bii);
                player.increasePoints(difficulty*Alien.getPoints());
            }
            ++bii;
        }
        ++ii;
    }
}

void Game::updateShootingAliens()
{
    shootingAlienSpawnNow += 0.03 ;
    if (shootingAlienSpawnNow >= alienSpawnCooldown)
    {
        shootingAliens.push_back(ShootingAlien{&window, &shootingAlienTexture, static_cast<float>(rand() % (window.getSize().x - shootingAlienTexture.getSize().x)), static_cast<float>(-120),1,10,static_cast<float>(difficulty*1.7)});
        shootingAlienSpawnNow = 0;
    }
    unsigned int ii=0;
    for (auto &sAl: shootingAliens)
    {
        sAl.update();
        shootingNow += 0.2;
        if (shootingNow >= alienSpawnCooldown)
        {
            createAlienBullet(sAl);
            audio.piu(false);
            shootingNow = 0;
        }
        if(sAl.killMe())
            shootingAliens.erase(shootingAliens.begin()+ii);

        unsigned int bii=0;
        for(auto &a:bulletsBank)
        {
            if(sAl.collision(a.getCenter(), a.getDiameter()))
            {
                shootingAliens.erase(shootingAliens.begin() + ii);
                bulletsBank.erase(bulletsBank.begin()+bii);
                player.increasePoints(difficulty* sAl.getPoints());
            }
            ++bii;
        }
        ++ii;
    }
}

void Game::updateOnScreenStats()
{
    string playerStatsStr="PLAYER";
    playerStatsStr+="    HP ";
    playerStatsStr+= to_string(player.getHP());
    playerStatsStr+="    SCR ";
    playerStatsStr+=to_string(player.getPoints());
    playerStats.setString(playerStatsStr);
    playerStats.setPosition(window.getSize().x/2-playerStats.getLocalBounds().width/2,0);
}


void Game::updateInterface()
{
    statsBackground.setSize(sf::Vector2f(window.getSize().x, 60));
    statsBackground.setPosition(0,0);
    statsBackground.setFillColor(backColour);
    window.draw(statsBackground);
    updateOnScreenStats();
    window.draw(playerStats);
}


bool Game::update()
{
    window.clear(sf::Color::Black);
    window.draw(background);
    updateBullets();
    if(!updatePlayer())
        return false;
    updateAsteroids();
    updateAliens();
    updateShootingAliens();
    updateInterface();
    if(!steer())
        return false;
    window.display();
    return true;
}


void Game::gameOver()
{
    sf::Text gameOverTxt;
    gameOverTxt.setFillColor(sf::Color::Red);
    gameOverTxt.setFont(font);
    gameOverTxt.setCharacterSize(100);
    sf::Text scoreTxt=gameOverTxt;
    gameOverTxt.setString("Game over!");
    string scoreStr="Score: ";
    scoreStr+=to_string(player.getPoints());
    scoreTxt.setString(scoreStr);
    gameOverTxt.setPosition(window.getSize().x/2-gameOverTxt.getLocalBounds().width/2,window.getSize().y/2-gameOverTxt.getLocalBounds().height/2-scoreTxt.getLocalBounds().height);
    scoreTxt.setPosition(window.getSize().x/2-scoreTxt.getLocalBounds().width/2,window.getSize().y/2-scoreTxt.getLocalBounds().height/2+gameOverTxt.getLocalBounds().height);
    window.draw(gameOverTxt);
    window.draw(scoreTxt);
    window.display();
    sf::Clock clock;
    sf::Time elapsedTime;
    do
    {
        elapsedTime = clock.getElapsedTime();
    }
    while(elapsedTime!=sf::seconds(1));
}