
#ifndef SPACE_SHOOTER_SETTINGS_H
#define SPACE_SHOOTER_SETTINGS_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Audio.h"

#define SETTINGS_ITEMS 5
class Settings {
public:
    Settings(float x, float y, sf::RenderWindow &, sf::Font &);
    void draw();
    short settingsUpdate();
    void moveUp();
    void moveDown();
    void loadBackground();
    void drawBackground();
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
