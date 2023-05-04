#include <SFML/Graphics.hpp>
#include "Menu.h"
#include <iostream>
using namespace std;

Menu::Menu(float x, float y) {
    if (!font.loadFromFile("../ethnocentric rg.ttf")){
        cout << "Error occured during loading a font";
    }
    //Title
    menu[0].setFont(font);
    menu[0].setFillColor(Color::Blue);
    menu[0].setString("Tutaj bedzie tytul");
    menu[0].setCharacterSize(60);
    menu[0].setPosition(Vector2f (500, 50));
    //Play
    menu[1].setFont(font);
    menu[1].setFillColor(Color::Blue);
    menu[1].setString("Play");
    menu[1].setCharacterSize(50);
    menu[1].setPosition(1000, 200);
    //Settings
    menu[2].setFont(font);
    menu[2].setFillColor(Color::Blue);
    menu[2].setString("Settings");
    menu[2].setCharacterSize(50);
    menu[2].setPosition(1000, 350);
    //How to play
    menu[3].setFont(font);
    menu[3].setFillColor(Color::Blue);
    menu[3].setString("How to play");
    menu[3].setCharacterSize(50);
    menu[3].setPosition(1000, 500);
    //Credits
    menu[4].setFont(font);
    menu[4].setFillColor(Color::Blue);
    menu[4].setString("Credits");
    menu[4].setCharacterSize(50);
    menu[4].setPosition(1000, 650);

    Selected_index = 0;
}

void Menu::draw(RenderWindow &window) {
    for (const auto & i : menu)
    {
        window.draw(i);
    }

}

void Menu::Move_Up() {
   if (Selected_index - 1 >= 1)
   {
       menu[Selected_index].setFillColor(Color::White);
       Selected_index--;
       menu[Selected_index].setFillColor(Color::Blue);
   }
}

void Menu::Move_Down(){
    if (Selected_index + 1 < MENU_ITEMS)
    {
        menu[Selected_index].setFillColor(Color::White);
        Selected_index++;
        menu[Selected_index].setFillColor(Color::Blue);
    }
}


