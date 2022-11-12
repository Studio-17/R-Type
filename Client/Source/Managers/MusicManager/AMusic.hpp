/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** AMusic
*/

#ifndef AMUSIC_HPP_
    #define AMUSIC_HPP_

    #include <nlohmann/json.hpp>

    #include "MyMusic.hpp"

/**
 * @brief Class containing all elements of an Music
 */
class AMusic {
    public:
        /**
         * @brief Construct a new AMusic object
         * 
         * @param jsonData path to the music file
         */
        AMusic(nlohmann::json const &jsonData);
        /**
         * @brief Destroy the AMusic object
         * 
         */
        ~AMusic() {};

        /**
         * @brief Get the AMusic object
         *
         * @return MyAMusic& AMusic of the asset
         */
        MyMusic &getMusic();

    protected:
    private:
        MyMusic _music; ///< Music of the asset
};

#endif /* !AMUSIC_HPP_ */
