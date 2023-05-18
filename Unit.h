//
// Created by Bartłomiej Pruszczyk on 07/05/2023.
//

#ifndef SPACE_SHOOTER_UNIT_H
#define SPACE_SHOOTER_UNIT_H

class Unit {

public:
    Unit(sf::RenderWindow &, sf::Texture &);
    Unit(sf::RenderWindow &, sf::Texture &, int);

    void moveX(float px, bool direction);
    void moveY(float px, bool direction);
    void moveCircular(int rad, bool direction);
    void rotate(int ang);
    void loadTexture();
    void setPlayerPosition();
    void setEnemyPosistion(float x, float y);
    void setSize(float size);
    void showSprite();
    void decreaseHP();

    int getHP() const;
    float getXLeft() const;
    float getXCenter() const;
    float getY() const;
    sf::Vector2f getCenter() const;
    sf::Vector2f getBounds() const;

    bool collision(sf::Vector2f centerV, sf::Vector2f boundsV) const;
    bool collision(sf::Vector2f centerV, float diameter) const;
    bool killMe() const;
    bool isDead() const;

private:
    sf::RenderWindow & window;
    int hp;
    sf::Texture & texture;
    sf::Sprite sprite;
};


#endif //SPACE_SHOOTER_UNIT_H
