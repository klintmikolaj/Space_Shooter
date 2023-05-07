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
    std::vector<Shoot> bulletsBank;
    sf::Texture bulletTexture;

public:
    explicit Game(Player&, sf::RenderWindow&, sf::Font&);
    void run();
    void update();
    void display();
    void steer();
    void drawInterface();
    void drawPlayerStuff();
    void bulletMaker(Player& playerArg, bool turnArg);
    void masterOfBullets();
};


#endif //SPACE_SHOOTER_GAME_H
