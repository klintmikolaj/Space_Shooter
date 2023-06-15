
#ifndef SPACE_SHOOTER_SETTINGS_H
#define SPACE_SHOOTER_SETTINGS_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Audio.h"

#define SETTINGS_ITEMS 5
class Settings {
public:
    Settings(float x, float y, sf::RenderWindow &, sf::Font &);

    /*
     * loading background
     * drawing background
     * clearing old window and making new one
     * displaying the new window
    */
    void draw();

    /*
     * loading music
     * checks if any key is pressed and calls specific functions
     * lets the player exit the settings window
    */
    short settingsUpdate();

    /*
     * Both functions let the player maneuver in menu
     * Press up arrow to go up
     * Press down arrow to go down
    */
    void moveUp();
    void moveDown();

    /*
     * loading background texture from file
    */
    void loadBackground();

    /*
     * setting new background texture
    */
    void drawBackground();

    /*
     * loading and playing music
    */
    void musicLoad();

private:
    sf::RenderWindow &window;
    int Selected_index;
    Audio audio;
    sf::Font & font;
    sf::Text settings[SETTINGS_ITEMS];
    sf::Texture backgroundTexture;
    sf::Sprite background;
};


#endif //SPACE_SHOOTER_SETTINGS_H
