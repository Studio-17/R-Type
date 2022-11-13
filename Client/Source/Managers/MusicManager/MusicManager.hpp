/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** MusicManager
*/

#ifndef MUSICMANAGER_HPP_
    #define MUSICMANAGER_HPP_

    #include <string>
    #include <vector>
    #include <unordered_map>

    #include "AMusic.hpp"

/**
 * @brief Class to store all Musics
 * 
 */
class MusicManager {
    public:
        /**
         * @brief Construct a new Music Manager object
         * 
         * @param musicsFile path to the json containing all the musics
         */
        MusicManager(std::string const &musicsFile);
        /**
         * @brief Construct a new Music Manager object
         * 
         */
        MusicManager() {};
        /**
         * @brief Destroy the Music Manager object
         * 
         */
        ~MusicManager() {};

        /**
         * @brief Get the Music at index sent as param
         *
         * @param index Index of the Music in map
         * @return Music Music from the map
         */
        AMusic at(std::string const &index) const;

        /**
         * @brief Load all Musics from a config file
         *
         * @param filepath Configuration file path containing data of all Musics
         */
        void loadMusics(std::string const &filepath);

    protected:
    private:
        /**
         * @brief Function to save Musics in configuration file all Musics
         *
         * @param filepath Path of the file to save Musics
         */
        void saveMusics(std::string const &filepath);

        std::unordered_map<std::string, AMusic> _musics; ///< map of all Musics
};

#endif /* !MUSICMANAGER_HPP_ */
