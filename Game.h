
#ifndef SPACE_SHOOTER_GAME_H
#define SPACE_SHOOTER_GAME_H


class Game {
private:
    sf::RenderWindow window;
    sf::Event event;
public:
    Game();
    void run();
    void update();
    void display();
};


#endif //SPACE_SHOOTER_GAME_H
