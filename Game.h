#ifndef SPACE_SHOOTER_GAME_H
#define SPACE_SHOOTER_GAME_H

#include "Player.h"
#include "Audio.h"
#include "Shoot.h"
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
    sf::Texture bulletTexture;

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
//    virtual ~Game();
};


#endif //SPACE_SHOOTER_GAME_H
