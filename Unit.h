//
// Created by Bartłomiej Pruszczyk on 07/05/2023.
//

#ifndef SPACE_SHOOTER_UNIT_H
#define SPACE_SHOOTER_UNIT_H


class Unit {

public:
    Unit(sf::RenderWindow &, sf::Texture &);
    Unit(sf::RenderWindow &, sf::Texture &, int);

    void moveX(char px, bool direction);
    void moveY(float px);
    void moveCircular(int rad, bool direction);
    void rotate(int ang);
    void loadTexture();
    void setPlayerPosition();
    void setEnemyPosistion(float x, float y);
    void setSize(float size);
    void showSprite();

    int getHP() const;
    float getXLeft() const;
    float getXCenter() const;
    float getY() const;
    bool killMe() const;

private:
    sf::RenderWindow & window;
    int hp;
    sf::Texture & texture;
    sf::Sprite sprite;
};


#endif //SPACE_SHOOTER_UNIT_H
