/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Sound
*/

#ifndef SOUND_HPP_
#define SOUND_HPP_

#include <raylib.h>
#include <string>

class Sound {
    public:
        /**
         * @brief Construct a new My Sound object
         *
         * @param filename
         */
        Sound(std::string const &filename);

        /**
         * @brief Construct a new My Sound object
         */
        Sound();
        /**
         * @brief Destroy the My Sound object
         */
        ~Sound();

        /**
         * @brief Start music playing
         */
        void play();
        /**
         * @brief Stop music playing
         */
        void stop();
        /**
         * @brief Pause music playing
         */
        void pause();
        /**
         * @brief Resume playing paused music
         */
        void resume();

        /**
         * @brief Check if music is playing
         *
         * @return true
         * @return false
         */
        bool isPlaying() const;
        /**
         * @brief Set the Volume object
         *
         * @param volume
         */
        void setVolume(float volume) override;

    protected:
    private:
        Sound _sound; ///< Sound object
    private:
};

#endif /* !SOUND_HPP_ */
