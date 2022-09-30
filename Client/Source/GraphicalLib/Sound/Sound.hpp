/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Sound
*/

#ifndef SOUND_HPP_
#define SOUND_HPP_

#include <string>

class Sound {
    public:
        Sound(std::string const &filename);
        ~Sound();

        void play();
        void stop();
        void pause();
        void resume();

        bool isPlaying();
        void setVolume(float volume);

    protected:
    private:
        Sound _sound;
};

#endif /* !SOUND_HPP_ */
