#ifndef SPACE_SHOOTER_GAME_H
#define SPACE_SHOOTER_GAME_H

#include "Player.h"
#include "Audio.h"

using namespace std;
using namespace sf;

class Game {
private:
    RenderWindow& window;
    Player& player;
    Event event;
    Font font;
    Text playerStats;
    Audio audio;
public:
    explicit Game(Player&, RenderWindow&);
    void run();
    void update();
    void display();
};


#endif //SPACE_SHOOTER_GAME_H
