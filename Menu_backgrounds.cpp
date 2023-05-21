//
// Created by indianajones on 5/21/23.
//

#include "Menu_backgrounds.h"

Menu_backgrounds::Menu_backgrounds(float x, float y, sf::RenderWindow &window): window(window) {

}

void Menu_backgrounds::setBackgroundTexture() {
    creditsTexture.loadFromFile("../textures/credits.png");
    howToPlayTexture.loadFromFile("../textures/how_to_play.png");
}

void Menu_backgrounds::drawCredits() {
    credits.setTexture(creditsTexture);
    window.draw(credits);
}

void Menu_backgrounds::drawHowToPlay() {
    howToPlay.setTexture(howToPlayTexture);
    window.draw(howToPlay);
}

