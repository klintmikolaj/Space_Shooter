//
// Created by indianajones on 4/29/23.
//

#include "Audio.h"

Audio::Audio()
{
    piuBuffer.loadFromFile("../audio/piu.wav");
    dziuBuffer.loadFromFile("../audio/dziu.wav");

}

void Audio::bgMusicLoad(bool menu)
{
    if(menu)
        music.openFromFile("../audio/SpaceShooterMenu.wav");
    else
        music.openFromFile("../audio/SpaceShooterTheme.wav");
    music.setLoop(true);
    music.setVolume(50.f);
}

void Audio::bgMusicPlay()
{
    music.play();
}

void Audio::piu(bool piu)
{
    if(piu)
        sound.setBuffer(piuBuffer);
    else
        sound.setBuffer(dziuBuffer);
    sound.play();
}

void Audio::bgMusicStop()
{
    music.stop();
}