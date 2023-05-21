#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Menu.h"
#include "Menu_backgrounds.h"
#include "Settings.h"

using namespace std;
using namespace sf;

int main()
{
    const int windowWidth=1000;
    const int windowHeight=800;
    string name="adam";
    RenderWindow window;
    Font font;
    font.loadFromFile("../fonts/ethnocentricRg.otf");
    window.create(VideoMode(windowWidth, windowHeight), "Space shooter (name subject to change)",Style::Close);
    Menu menu{window, font};
    short difficulty=1;
    short temp;
    do
    {
        temp=menu.menu_update();
        if(temp==2)
        {
            Settings settings(windowWidth, windowHeight, window, font);
            short temp2;
            temp2 = settings.settingsUpdate();
            if(temp2>0)
                difficulty=temp2;
        }
        if(temp==3)
        {
            Menu_backgrounds menuBackground{window};
            menuBackground.draw(false);
        }
        if (temp==4)
        {
            Menu_backgrounds menuBackground{window};
            menuBackground.draw(true);
        }
    }
    while(temp>1);
    if(temp==1)
    {
        Game game(name, window, font, difficulty);
        game.run();
    }


    return 0;
}
