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

/**
 * @brief Music class
 *
 */
class MyMusic {
    public:
        /**
         * @brief Construct a new My Music object
         *
         * @param filename path to the music
         */
        MyMusic(std::string const &filename);
        /**
         * @brief Destroy the My Music object
         *
         */
        ~MyMusic();

        /**
         * @brief Play the music
         *
         */
        void play();
        /**
         * @brief Stop the music
         *
         */
        void stop();
        /**
         * @brief Pause the music
         *
         */
        void pause();
        /**
         * @brief Resume the music
         *
         */
        void resume();

        /**
         * @brief Check if the music is playing
         *
         * @return true if the music is playing
         * @return false if the music is not playing
         */
        bool isPlaying() const;
        /**
         * @brief Set the volume of the music
         *
         * @param volume volume of the music
         */
        void setVolume(float volume);

        /**
         * @brief Get the volume of the music
         *
         * @return float volume of the music
         */
        float getVolume() const;
        /**
         * @brief Update the stream
         *
         */
        void updateStream();

    protected:
    private:
        Music _music; ///< Music object
        float _volume; ///< Volume of the music

    protected:
    private:
};

#endif /* !MYMUSIC_HPP_ */
