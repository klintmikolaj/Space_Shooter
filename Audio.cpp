//
// Created by indianajones on 4/29/23.
//

#include "Audio.h"

void Audio::bgMusicLoad()
{
    music.openFromFile("../podruga.flac");
}

void Audio::bgMusicPlay()
{
    music.setVolume(10);
    music.play();
}

Audio::Audio()
{

}
