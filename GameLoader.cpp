//
// Created by Bartłomiej Pruszczyk on 12/06/2023.
//

#include "GameLoader.h"
#include "Menu_backgrounds.h"
#include "Settings.h"
#include "Game.h"

GameLoader::GameLoader(): name{"adam"}, difficulty{1}, exit{false}, windowWidth{1000}, windowHeight{800}
{
    window.create(sf::VideoMode(windowWidth, windowHeight), "Space Shooter (name subject to change)",sf::Style::Close);
    font.loadFromFile("../fonts/ethnocentricRg.otf");
}

void GameLoader::load()
{
    Menu menu{window, font};
    short temp;
    while (!exit)
    {
        do
        {
            temp = menu.menu_update();
            if (temp == 2)
            {
                Settings settings{static_cast<float>(windowWidth), static_cast<float>(windowHeight), window, font};
                short temp2;
                temp2 = settings.settingsUpdate();
                if (temp2 > 0)
                    difficulty = temp2;
            }
            else if (temp == 3)
            {
                Menu_backgrounds menuBackground{window};
                menuBackground.draw(false);
            }
            else if (temp == 4)
            {
                Menu_backgrounds menuBackground{window};
                menuBackground.draw(true);
            }
        }
        while (temp > 1 && temp < 5);

        if (temp == 5)
        {
            return;
        }

        if (temp == 1)
        {
            Game game(name, window, font, difficulty);
            game.run();
        }
    }
}