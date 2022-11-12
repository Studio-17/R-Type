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

/**
 * @brief MySound class
 * 
 */
class MySound {
    public:
        /**
         * @brief Construct a new My Sound object
         * 
         */
        MySound(std::string const &texturePath);
        /**
         * @brief Destroy the My Sound object
         * 
         */
        ~MySound();

        /**
         * @brief Play the sound[[ maybe_unused ]]
         * 
         */
        void play();
        /**
         * @brief Stop the sound
         * 
         */
        void stop();
        /**
         * @brief Pause the sound
         * 
         */
        void pause();
        /**
         * @brief Resume the sound
         * 
         */
        void resume();

        /**
         * @brief Check if the sound is playing
         * 
         * @return true 
         * @return false 
         */
        bool isPlaying() const;
        /**
         * @brief Set the volume of the sound
         * 
         * @param volume 
         */
        void setVolume(float volume);

    protected:
    private:
        Sound _sound; ///< Sound object
};

#endif /* !MYSOUND_HPP_ */
