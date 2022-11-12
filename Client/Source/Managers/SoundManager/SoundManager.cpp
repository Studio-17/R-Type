/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** SoundManager
*/

#include <fstream>
#include <exception>
#include <iostream>

#include "SoundManager.hpp"
#include "fileConfig.hpp"

SoundManager::SoundManager(std::string const &soundsFile)
{
    loadSounds(soundsFile);
}

ASound SoundManager::at(std::string const &index) const
{
    return _sounds.at(index);
}

void SoundManager::loadSounds(std::string const &filepath)
{
    nlohmann::json jsonData;
    try {
        jsonData = getJsonData(filepath);
    } catch (std::exception const &e) {
        std::cerr << e.what() << std::endl;
        return;
    }
    for (auto oneData : jsonData) {
        _sounds.emplace(oneData.value("title", "error title"), ASound(oneData));
    }
}
