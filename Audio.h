//
// Created by indianajones on 4/29/23.
//

#ifndef SPACE_SHOOTER_AUDIO_H
#define SPACE_SHOOTER_AUDIO_H

#include <SFML/Audio.hpp>

class Audio {
public:
    Audio();

    /*
     *@param menu
     * checking if player is in menu and playing specific audio
     * looping audio
    */
    void bgMusicLoad(bool menu);

    /*
     * playing music
    */
    void bgMusicPlay();

    /*
     * stopping music from playing
    */
    void bgMusicStop();

    /*
     * @param piu
     * playing specific blaster sound
    */
    void piu(bool piu);

    /*
    * playing specific sound
    */
    void ough();
private:
    sf::Music music;
    sf::Sound sound;
    sf::Sound oughSound;
    sf::SoundBuffer piuBuffer;
    sf::SoundBuffer dziuBuffer;
    sf::SoundBuffer oughBuffer;
};


#endif //SPACE_SHOOTER_AUDIO_H
