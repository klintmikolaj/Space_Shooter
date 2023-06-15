//
// Created by Bartłomiej Pruszczyk on 07/05/2023.
//

#ifndef SPACE_SHOOTER_UNIT_H
#define SPACE_SHOOTER_UNIT_H

class Unit
{
    public:
        Unit(sf::RenderWindow &, sf::Texture &);

        bool visible(sf::Vector2f position, sf::Vector2f movement);
        void move(float x, float y, bool dirX, bool dirY, bool isAlien);
        void rotate(int ang);
        void loadTexture();
        void setPlayerPosition();
        void setEnemyPosistion(float x, float y);
        void setSize(float size);
        void showSprite();

        float getXLeft() const;
        float getXCenter() const;
        float getY() const;
        float getDown() const;
        sf::Vector2f getCenter() const;
        sf::Vector2<unsigned int> getBounds() const;

        bool collision(sf::Vector2f centerV, sf::Vector2<unsigned int>boundsV) const;
        bool collision(sf::Vector2f centerV, float diameter) const;
        bool killMe() const;

    private:
        sf::RenderWindow & window;
        sf::Texture & texture;
        sf::Sprite sprite;
};


#endif //SPACE_SHOOTER_UNIT_H
