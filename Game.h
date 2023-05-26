#ifndef SPACE_SHOOTER_GAME_H
#define SPACE_SHOOTER_GAME_H

#include "Player.h"
#include "Audio.h"
#include "Shoot.h"
#include "Asteroid.h"
#include "Alien.h"
#include "ShootingAlien.h"
#include <vector>



class Game {
private:
    sf::RenderWindow& window;
    sf::Font& font;
    Player player;
    sf::Event event;
    sf::Text playerStats;
    Audio audio;
    std::vector<Shoot*> bulletsBank;
    std::vector<Shoot*> alienBulletsBank;
    std::vector<Asteroid*> asteroids;
    std::vector<Alien*> aliens;
    std::vector<ShootingAlien*> shootingAliens;
    Unit* lastEnemy;
    Shoot* lastBullet;
    sf::Sprite background;
    sf::Texture playerTexture;
    sf::Texture backgroundTexture;
    sf::Texture bulletTexture;
    sf::Texture alienBulletTexture;
    sf::Texture asteroidTexture1;
    sf::Texture asteroidTexture2;
    sf::Texture alienTexture1;
    sf::Texture shootingAlienTexture;
    sf::Color backColour;
    sf::RectangleShape statsBackground;
    float asteroidSpawnNow;
    float asteroidSpawnCooldown;
    float alienSpawnNow;
    float shootingAlienSpawnNow;
    float shootingNow;
    float alienSpawnCooldown;
    int multiplier;
    int frameCount;
    short & difficulty;
    bool isLeft;
    bool isX;
    bool isUp;
    bool isY;

public:
    Game(std::string& nameArg, sf::RenderWindow& windowArg, sf::Font& fontArg, short& difficultyArg);
    void run();
    bool update();
    void display();
    bool steer();
    void drawInterface();
    void drawPlayerStuff();
    void loadTextures();
    void loadPlayerStats();
    void playerCollision(std::vector<Asteroid*> & unitBank);
    void playerCollision(std::vector<Alien*> & unitBank);
    void playerCollision(std::vector<ShootingAlien*> & unitBank);
    void playerCollision(std::vector<Shoot*> & bulletBank);
    bool playerManager();
    void bulletMaker(Player& playerArg);
    void alienBulletMaker(ShootingAlien*& enemyArg);
    void bulletDestroyer(Shoot*& a, unsigned int& ii);
    void masterOfBullets();
    void asteroidAhead();
    void alienAttack();
    void shootingAlienAttack();
    void asteroidsSetSpawners();
    void aliensSetSpawners();
    void statsUpdate();
    void setCredits();
    void setHowToPlay();
    void gameOver();
};


#endif //SPACE_SHOOTER_GAME_H
