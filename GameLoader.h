//
// Created by Bartłomiej Pruszczyk on 12/06/2023.
//

#ifndef SPACE_SHOOTER_GAMELOADER_H
#define SPACE_SHOOTER_GAMELOADER_H

#include <SFML/Graphics.hpp>
#include "Menu.h"

class GameLoader
{
    public:
        GameLoader();

        /*
         * creates Menu object
         * creates windows for specific Menu_backgrounds options
         * lets player exit the window
         * creates game object and runs the game
        */
        void load();

    private:
        const int windowWidth;
        const int windowHeight;
        sf::RenderWindow window;
        sf::Font font;
        short difficulty;
        bool exit;
};


#endif //SPACE_SHOOTER_GAMELOADER_H
