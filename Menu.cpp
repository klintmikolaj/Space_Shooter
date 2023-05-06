#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Game.h"
#include <iostream>
using namespace std;

Menu::Menu(float x, float y, RenderWindow &window1) :window(window1) {
    if (!font.loadFromFile("../ethnocentric rg.ttf")){
        cout << "Error occured during loading a font";
    }

    //Title
    menu[0].setFont(font);
    menu[0].setFillColor(Color::Blue);
    menu[0].setString("Space Shooter");
    menu[0].setCharacterSize(50);
    menu[0].setPosition(200, 50);
    //Play
    menu[1].setFont(font);
    menu[1].setFillColor(Color::White);
    menu[1].setString("Play");
    menu[1].setCharacterSize(45);
    menu[1].setPosition(x/2, 200);
    //Settings
    menu[2].setFont(font);
    menu[2].setFillColor(Color::Blue);
    menu[2].setString("Settings");
    menu[2].setCharacterSize(45);
    menu[2].setPosition(x/2, 350);
    //How to play
    menu[3].setFont(font);
    menu[3].setFillColor(Color::Blue);
    menu[3].setString("How to play");
    menu[3].setCharacterSize(45);
    menu[3].setPosition(x/2, 500);
    //Credits
    menu[4].setFont(font);
    menu[4].setFillColor(Color::Blue);
    menu[4].setString("Credits");
    menu[4].setCharacterSize(45);
    menu[4].setPosition(x/2, 650);

    Selected_index = 1;
}

void Menu::draw()//RenderWindow &window)
     {
    window.clear(Color::Black);
    for (int i = 0; i < MENU_ITEMS; i++)
    {
        window.draw(menu[i]);

    }
    window.display();
}

void Menu::Move_Up() {
   if (Selected_index - 1 >= 0)
   {
       menu[Selected_index].setFillColor(Color::Blue);
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
        menu[Selected_index].setFillColor(Color::Blue);
        Selected_index++;
        if (Selected_index == 5)
        {
            Selected_index = 1;
        }
        menu[Selected_index].setFillColor(Color::White);
    }
}

int Menu::menu_update() {
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
                    return (Selected_index + 1);
                }
            }
        }
        draw();
    }
}


