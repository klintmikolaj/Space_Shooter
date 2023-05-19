//
// Created by indianajones on 4/29/23.
//

#include "Audio.h"

Audio::Audio()
{
    buffer.loadFromFile("../audio/piu.wav");
    sound.setBuffer(buffer);
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


void Audio::piu()
{
    sound.play();
}

void Audio::bgMusicStop()
{
    music.stop();
}