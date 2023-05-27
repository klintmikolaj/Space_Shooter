#include "Settings.h"
#include "Audio.h"
using namespace std;
using namespace sf;

Settings::Settings(float x, float y, sf::RenderWindow &windowArg, sf::Font &fontArg): window(windowArg), font(fontArg) {

    settings[0].setFont(font);
    settings[0].setFillColor(Color::Cyan);
    settings[0].setString("Set difficulty");
    settings[0].setCharacterSize(60);
    settings[0].setPosition(x/4 - 90, 50);

    settings[1].setFont(font);
    settings[1].setFillColor(Color::White);
    settings[1].setString("1: NOVICE EXPLORER");
    settings[1].setCharacterSize(45);
    settings[1].setPosition(x/4 - 150, 250);

    settings[2].setFont(font);
    settings[2].setFillColor(Color::Cyan);
    settings[2].setString("2: SPACE COMMANDER");
    settings[2].setCharacterSize(45);
    settings[2].setPosition(x/4 - 150, 375);

    settings[3].setFont(font);
    settings[3].setFillColor(Color::Cyan);
    settings[3].setString("3: BOUNTY HOUTER");
    settings[3].setCharacterSize(45);
    settings[3].setPosition(x/4 - 150, 500);

    settings[4].setFont(font);
    settings[4].setFillColor(Color::Cyan);
    settings[4].setString("4: ASTRAL DEITY");
    settings[4].setCharacterSize(45);
    settings[4].setPosition(x/4 - 150, 625);

    Selected_index = 1;
}

void Settings::draw() {
    loadBackground();
    drawBackground();
    window.clear(Color::Black);
    window.draw(background);
    for (int i = 0; i < SETTINGS_ITEMS; i++)
    {
        window.draw(settings[i]);
    }
    window.display();
}

short Settings::settingsUpdate() {
    musicLoad();
    Event event;
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {

            if (event.type == Event::Closed)
            {
                return 0;
            }
            if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::Up)
                {
                    moveUp();
                }
                if (event.key.code == Keyboard::Down)
                {
                    moveDown();
                }
                if (event.key.code == Keyboard::Enter)
                {
                    audio.bgMusicStop();
                    return (Selected_index);
                }
                if (event.key.code == Keyboard::Escape)
                {
                    return 0;
                }
            }
        }
        draw();
    }

    return 0;
}

void Settings::moveUp()
{
    if (Selected_index - 1 >= 0)
    {
        settings[Selected_index].setFillColor(Color::Cyan);
        Selected_index--;
        if (Selected_index == 0)
        {
            Selected_index = 4;
        }
        if (Selected_index == 4) settings[Selected_index].setFillColor(Color::Red);
        else settings[Selected_index].setFillColor(Color::White);
    }
}

void Settings::moveDown() {
    if (Selected_index + 1 <= 5)
    {
        settings[Selected_index].setFillColor(Color::Cyan);
        Selected_index++;
        if (Selected_index == 5)
        {
             Selected_index = 1;
        }
        if (Selected_index == 4) settings[Selected_index].setFillColor(Color::Red);
        else settings[Selected_index].setFillColor(Color::White);
    }
}

void Settings::loadBackground() {
    Texture texture;
    backgroundTexture.loadFromFile("../textures/hangar_esc.png");
}

void Settings::drawBackground() {
    background.setTexture(backgroundTexture);
}

void Settings::musicLoad()
{
    audio.bgMusicLoad(true);
    audio.bgMusicPlay();
}
