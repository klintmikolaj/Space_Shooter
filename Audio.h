//
// Created by indianajones on 4/29/23.
//

#ifndef SPACE_SHOOTER_AUDIO_H
#define SPACE_SHOOTER_AUDIO_H

#include <SFML/Audio.hpp>

class Audio {
public:
    Audio();
    void bgMusicLoad(bool menu);
    void bgMusicPlay();
    void bgMusicStop();

    void piu(bool piu);
    void ough();
private:
    sf::Music music;
    sf::Sound sound;
    sf::SoundBuffer piuBuffer;
    sf::SoundBuffer dziuBuffer;
    sf::SoundBuffer oughBuffer;
};


#endif //SPACE_SHOOTER_AUDIO_H
