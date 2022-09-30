/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Music
*/

#ifndef MUSIC_HPP_
#define MUSIC_HPP_

#include <string>
#include "Error.hpp"

class Music {
    public:
        Music(std::string const &filename);
        ~Music();

        void play();
        void stop();
        void pause();
        void resume();

        void isPlaying();
        void setVolume(float volume);
        void updateStream();

    protected:
    private:
        Music _music;
};

#endif /* !MUSIC_HPP_ */
