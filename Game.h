#ifndef SPACE_SHOOTER_GAME_H
#define SPACE_SHOOTER_GAME_H

#include "Player.h"
#include "Audio.h"
#include "Shoot.h"
#include "Asteroid.h"
#include "Alien.h"
#include <vector>

class Game {
private:
    sf::RenderWindow& window;
    sf::Font& font;
    Player& player;
    sf::Event event;
    sf::Text playerStats;
    Audio audio;
    std::vector<Shoot*> bulletsBank;
    std::vector<Asteroid*> asteroids;
    std::vector<Alien*> aliens;
    sf::Sprite background;
    sf::Texture backgroundTexture;
    sf::Texture bulletTexture;
    sf::Texture asteroidTexture1;
    sf::Texture asteroidTexture2;
    sf::Texture alienTexture1;
    sf::Color backColour;
    sf::RectangleShape statsBackground;
    float asteroidSpawnNow;
    float asteroidSpawnCooldown;
    float alienSpawnNow;
    float alienSpawnCooldown;
    bool isSkip;
    bool isLeft;
    bool isX;
    bool isUp;
    bool isY;

public:
    Game(Player& playerArg, sf::RenderWindow& windowArg, sf::Font& fontArg);
    void run();
    void update();
    void display();
    void steer();
    void drawInterface();
    void drawPlayerStuff();
    void loadTextures();
    void loadPlayerStats();
    void playerManager();
    void bulletMaker(Player& playerArg, bool turnArg);
    void masterOfBullets();
    void asteroidAhead();
    void alienAttack();
    void asteroidsSetSpawners();
    void aliensSetSpawners();
    float setNumberRange(int max, int min);
    void statsUpdate();
    void setBackground();
};


#endif //SPACE_SHOOTER_GAME_H
