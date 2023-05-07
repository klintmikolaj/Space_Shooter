//
// Created by indianajones on 5/7/23.
//

#include "Asteroid.h"

Asteroid::Asteroid(RenderWindow &) {

}

void Asteroid::loadTexture() {
    asteroid1_Texture.loadFromFile("../Spaceship1.png");
    asteroid2_Texture.loadFromFile("../Starship_4.png");
    asteroid1_Texture.setSmooth(true);
    asteroid2_Texture.setSmooth(true);
    asteroid1_Sprite.setTexture(asteroid1_Texture);
    asteroid2_Sprite.setTexture(asteroid2_Texture);
    asteroid1_Sprite.scale(0.1f, 0.1f);
    asteroid2_Sprite.scale(0.1f, 0.1f);
}

void Asteroid::showSprite() {

}

void Asteroid::update() {

}

