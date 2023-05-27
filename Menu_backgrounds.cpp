//
// Created by indianajones on 5/21/23.
//

#include "Menu_backgrounds.h"

using namespace sf;

Menu_backgrounds::Menu_backgrounds(sf::RenderWindow &window): window(window)
{
}

void Menu_backgrounds::setBackgroundTexture()
{
    creditsTexture.loadFromFile("../textures/credits.png");
    howToPlayTexture.loadFromFile("../textures/how_to_play.png");
}

void Menu_backgrounds::draw(bool credits)
{
    audio.bgMusicLoad(true);
    audio.bgMusicPlay();
    setBackgroundTexture();
    window.clear();
    if(credits)
        bg.setTexture(creditsTexture);
    else
        bg.setTexture(howToPlayTexture);
    window.draw(bg);
    window.display();
    Event event;
    while(window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if(event.type==Event::Closed)
                return;
            if(event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
            {
                 return;
            }
        }
    }
}
