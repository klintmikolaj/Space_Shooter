#include <SFML/Graphics.hpp>
#include "Audio.h"
#include "Menu.h"
using namespace std;
using namespace sf;

Menu::Menu(RenderWindow &window1, Font & fontArg): window(window1), font(fontArg)
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
    menu[1].setPosition(window.getSize().x/2 + 50, 240);
    //Settings
    menu[2].setFont(font);
    menu[2].setFillColor(Color::Cyan);
    menu[2].setString("Difficulty");
    menu[2].setCharacterSize(45);
    menu[2].setPosition(window.getSize().x/2 + 50, 340);
    //How to play
    menu[3].setFont(font);
    menu[3].setFillColor(Color::Cyan);
    menu[3].setString("How to play");
    menu[3].setCharacterSize(45);
    menu[3].setPosition(window.getSize().x/2 + 50, 440);
    //Credits
    menu[4].setFont(font);
    menu[4].setFillColor(Color::Cyan);
    menu[4].setString("Credits");
    menu[4].setCharacterSize(45);
    menu[4].setPosition(window.getSize().x/2 + 50, 540);
    //Exit
    menu[5].setFont(font);
    menu[5].setFillColor(Color::Cyan);
    menu[5].setString("Exit");
    menu[5].setCharacterSize(45);
    menu[5].setPosition(window.getSize().x/2 + 50, 640);

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
           Selected_index = 5;
       }
       menu[Selected_index].setFillColor(Color::White);
   }
}

void Menu::Move_Down(){
    if (Selected_index + 1 <= MENU_ITEMS)
    {
        menu[Selected_index].setFillColor(Color::Cyan);
        Selected_index++;
        if (Selected_index == 6)
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

short Menu::menu_update()
{
    musicLoad();
    Event event;
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                return 5;
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
                if (event.key.code == Keyboard::Escape)
                {
                    audio.bgMusicStop();
                    return 5;
                }
            }
        }
        draw();
    }
    return 0;
}