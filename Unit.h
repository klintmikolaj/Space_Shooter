//
// Created by Bartłomiej Pruszczyk on 07/05/2023.
//

#ifndef SPACE_SHOOTER_UNIT_H
#define SPACE_SHOOTER_UNIT_H

class Unit
{
    public:
        Unit(sf::RenderWindow &, sf::Texture &);
//        Unit(sf::RenderWindow &, sf::Texture &, int);

        /*
        * lets the object move left-right
         * @param px
         * @param direction
        */
        void moveX(float px, bool direction);

        /*
         * lets the object move up-down
         * @param px
         * @param direction
        */
        void moveY(float px, bool direction);

//        void moveCircular(int rad, bool direction);
//        void rotate(int ang);

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
        void showSprite();

        /*
        * returns X position of an object
        */
        float getXLeft() const;

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
        sf::Vector2f getBounds() const;

        bool collision(sf::Vector2f centerV, sf::Vector2f boundsV) const;
        bool collision(sf::Vector2f centerV, float diameter) const;
        bool killMe() const;

    private:
        sf::RenderWindow & window;
        sf::Texture & texture;
        sf::Sprite sprite;
};


#endif //SPACE_SHOOTER_UNIT_H
