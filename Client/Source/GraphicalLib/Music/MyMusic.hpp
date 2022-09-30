/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** MyMusic
*/

#ifndef MYMUSIC_HPP_
#define MYMUSIC_HPP_

#include <string>
#include "raylib.h"

class MyMusic {
    public:
        MyMusic(std::string const &filename);
        ~MyMusic();

        void play();
        void stop();
        void pause();
        void resume();

        bool isPlaying() const;
        void setVolume(float volume);
        void updateStream();

    protected:
    private:
        Music _music;

    protected:
    private:
};

#endif /* !MYMUSIC_HPP_ */
