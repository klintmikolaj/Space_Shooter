#ifndef SPACE_SHOOTER_GAME_H
#define SPACE_SHOOTER_GAME_H

#include "Player.h"
#include "Audio.h"

class Game {
private:
    sf::RenderWindow& window;
    sf::Font& font;
    Player& player;
    sf::Event event;
    sf::Text playerStats;
    Audio audio;
public:
    explicit Game(Player&, sf::RenderWindow&, sf::Font&);
    void run();
    void update();
    void display();
};


#endif //SPACE_SHOOTER_GAME_H
