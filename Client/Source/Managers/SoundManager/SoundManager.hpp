/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** SoundManager
*/

#ifndef SOUNDMANAGER_HPP_
#define SOUNDMANAGER_HPP_

    #include <string>
    #include <vector>
    #include <unordered_map>

    #include "ASound.hpp"

class SoundManager {
    public:
        SoundManager(std::string const &soundsFile);
        SoundManager() {};
        ~SoundManager() {};

        /**
         * @brief Get the Sound at index sent as param
         *
         * @param index Index of the Sound in map
         * @return Sound Sound from the map
         */
        ASound at(std::string const &index) const;

        /**
         * @brief Load all Sounds from a config file
         *
         * @param filepath Configuration file path containing data of all Sounds
         */
        void loadSounds(std::string const &filepath);

    protected:
    private:
        /**
         * @brief Function to save Sounds in configuration file all Sounds
         *
         * @param filepath Path of the file to save Sounds
         */
        void saveSounds(std::string const &filepath);

        std::unordered_map<std::string, ASound> _sounds; ///< map of all Sounds
};

#endif /* !SOUNDMANAGER_HPP_ */
