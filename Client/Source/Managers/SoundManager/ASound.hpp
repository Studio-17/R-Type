/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** ASound
*/

#ifndef ASOUND_HPP_
    #define ASOUND_HPP_

    #include <nlohmann/json.hpp>

    #include "MySound.hpp"

/**
 * @brief Class containing all elements of an Sound
 */
class ASound {
    public:
        /**
         * @brief Construct a new ASound object
         * 
         * @param jsonData path to the sound file
         */
        ASound(nlohmann::json const &jsonData);
        /**
         * @brief Destroy the ASound object
         * 
         */
        ~ASound() {};

        /**
         * @brief Get the ASound object
         *
         * @return MyASound& ASound of the asset
         */
        MySound &getSound();

    protected:
    private:
        MySound _sound; ///< Sound of the asset
};

#endif /* !ASOUND_HPP_ */
