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
        void load();
    private:
        const int windowWidth;
        const int windowHeight;
        std::string name;
        sf::RenderWindow window;
        sf::Font font;
        short difficulty;
        bool exit;
};


#endif //SPACE_SHOOTER_GAMELOADER_H
