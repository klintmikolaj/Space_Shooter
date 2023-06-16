//
// Created by Bartłomiej Pruszczyk on 07/05/2023.
//

#ifndef SPACE_SHOOTER_UNIT_H
#define SPACE_SHOOTER_UNIT_H

class Unit
{
    public:
        Unit();
        Unit(sf::RenderWindow *, sf::Texture *);

        bool visible(sf::Vector2f position, sf::Vector2f movement);

        /*
         * lets the object move
         * @param x
         * @param y
         * @param dirX
         * @param dirY
        */
        void move(float x, float y, bool dirX, bool dirY, bool isAlien);


        /*
        * loads texture from file
        */

        void loadTexture();

        /*
        * sets player position depending on width and length of the window
        */
        void setPlayerPosition();

        /*
         * sets enemy position depending on given parameters
         * @param x
         * @param y
        */
        void setEnemyPosistion(float x, float y);

        /*
         * setting new scale for an object depending on the parameter
         * @param size
        */
        void setSize(float size);

        /*
        * drawing the sprite in window
        */
        void updateSprite();

        /*
        * returns X position of an object, exactly in the center depending on window width
        */
        float getXCenter() const;

        /*
        * returns Y position of an object
        */
        float getY() const;

        /*
        * returns Y position of an object increased by its size
        */
        float getDown() const;


        sf::Vector2f getCenter() const;

        /*
        * returns vector of textures size
        */
        sf::Vector2<unsigned int> getBounds() const;

        bool collision(sf::Vector2f centerV, sf::Vector2<unsigned int>boundsV) const;
        bool collision(sf::Vector2f centerV, float diameter) const;

        /*
         * returns boolean value should be unit destroyed
        */
        bool killMe() const;

    private:
        sf::RenderWindow * window;
        sf::Texture * texture;
        sf::Sprite sprite;
};


#endif //SPACE_SHOOTER_UNIT_H
