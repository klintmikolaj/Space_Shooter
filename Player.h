//
// Created by indianajones on 4/29/23.
//

#ifndef SPACE_SHOOTER_PLAYER_H
#define SPACE_SHOOTER_PLAYER_H

class Player
{
    public:
        explicit Player(std::string &, sf::RenderWindow &);
        Player(std::string &, sf::RenderWindow &, int);

        void move(bool direction);
        void loadTexture();
        void showSprite();

        int getHP() const;
        std::string getName() const;

    private:
        sf::RenderWindow & window;
        const std::string name;
        int hp;
        sf::Texture playerTexture;
        sf::Sprite playerSprite;
};


#endif //SPACE_SHOOTER_PLAYER_H
