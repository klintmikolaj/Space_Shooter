#include <SFML/Graphics.hpp>
#include "Audio.h"
#include "Menu.h"
#include <iostream>
using namespace std;
using namespace sf;

Menu::Menu(float x, float y, RenderWindow &window1, Font & fontArg): window(window1), font(fontArg)
{
    //Title
    menu[0].setFont(font);
    menu[0].setFillColor(Color::Cyan);
    menu[0].setString("Space Shooter");
    menu[0].setCharacterSize(80);
    menu[0].setPosition(12, 50);
    //Play
    menu[1].setFont(font);
    menu[1].setFillColor(Color::White);
    menu[1].setString("Play");
    menu[1].setCharacterSize(45);
    menu[1].setPosition(x/2 + 50, 250);
    //Settings
    menu[2].setFont(font);
    menu[2].setFillColor(Color::Cyan);
    menu[2].setString("Difficulty");
    menu[2].setCharacterSize(45);
    menu[2].setPosition(x/2 + 50, 375);
    //How to play
    menu[3].setFont(font);
    menu[3].setFillColor(Color::Cyan);
    menu[3].setString("How to play");
    menu[3].setCharacterSize(45);
    menu[3].setPosition(x/2 + 50, 500);
    //Credits
    menu[4].setFont(font);
    menu[4].setFillColor(Color::Cyan);
    menu[4].setString("Credits");
    menu[4].setCharacterSize(45);
    menu[4].setPosition(x/2 + 50, 625);

    Selected_index = 1;
}

void Menu::draw()//RenderWindow &window)
{
    Load_background();
    Draw_background();
    window.clear(Color::Black);
    window.draw(background);
    for (int i = 0; i < MENU_ITEMS; i++)
    {
        window.draw(menu[i]);
    }
    window.display();
}

void Menu::Move_Up() {
   if (Selected_index - 1 >= 0)
   {
       menu[Selected_index].setFillColor(Color::Cyan);
       Selected_index--;
       if (Selected_index == 0)
       {
           Selected_index = 4;
       }
       menu[Selected_index].setFillColor(Color::White);
   }
}

void Menu::Move_Down(){
    if (Selected_index + 1 <= MENU_ITEMS)
    {
        menu[Selected_index].setFillColor(Color::Cyan);
        Selected_index++;
        if (Selected_index == 5)
        {
            Selected_index = 1;
        }
        menu[Selected_index].setFillColor(Color::White);
    }
}

void Menu::Load_background()
{
    Texture texture;
    backgroundTexture.loadFromFile("../textures/hangar.png");
}

void Menu::Draw_background()
{
    background.setTexture(backgroundTexture);
}

void Menu::musicLoad()
{
    audio.bgMusicLoad(true);
    audio.bgMusicPlay();
}

int Menu::menu_update()
{
    musicLoad();
    Event event;
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {

            if (event.type == Event::Closed)
            {
                window.close();
                break;
            }
            if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::Up)
                {
                    Move_Up();
                }
                if (event.key.code == Keyboard::Down)
                {
                    Move_Down();
                }
                if (event.key.code == Keyboard::Enter)
                {
                    audio.bgMusicStop();
                    return (Selected_index);
                }
            }
        }
        draw();
    }

    return 0;
}