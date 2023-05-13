#ifndef SPACE_SHOOTER_GAME_H
#define SPACE_SHOOTER_GAME_H

#include "Player.h"
#include "Audio.h"
#include "Shoot.h"
#include "Asteroid.h"
#include <vector>

class Game {
private:
    sf::RenderWindow& window;
    sf::Font& font;
    Player& player;
    sf::Event event;
    sf::Text playerStats;
    Audio audio;
    std::vector<Shoot> bulletsBank;
    std::vector<Asteroid*> asteroids;
    sf::Texture bulletTexture;
    sf::Texture asteroidTexture;
    float spawnNow;
    float spawnCooldown;

public:
    Game(Player& playerArg, sf::RenderWindow& windowArg, sf::Font& fontArg);
    void run();
    void update();
    void display();
    void steer();
    void drawInterface();
    void drawPlayerStuff();
    void bulletMaker(Player& playerArg, bool turnArg);
    void masterOfBullets();
    void asteroidAhead();
    void setSpawners();
    float setNumberRange(int max, int min);
    int getSameValue(int value);
    void setBackground();
};


#endif //SPACE_SHOOTER_GAME_H
