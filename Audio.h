//
// Created by indianajones on 4/29/23.
//

#ifndef SPACE_SHOOTER_AUDIO_H
#define SPACE_SHOOTER_AUDIO_H

#include <SFML/Audio.hpp>

class Audio {
public:
    Audio();
    void bgMusicLoad();
    void bgMusicPlay();
private:
    sf::Music music;
};


#endif //SPACE_SHOOTER_AUDIO_H
