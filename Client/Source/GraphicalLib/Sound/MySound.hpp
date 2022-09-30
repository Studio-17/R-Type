/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** MySound
*/

#ifndef MYSOUND_HPP_
#define MYSOUND_HPP_

#include <string>
#include "raylib.h"

class MySound {
    public:
        MySound(std::string const &filename);
        ~MySound();

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

#endif /* !MYSOUND_HPP_ */
