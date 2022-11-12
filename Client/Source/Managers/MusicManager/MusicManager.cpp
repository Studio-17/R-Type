/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** MusicManager
*/

#include <fstream>
#include <exception>
#include <iostream>

#include "MusicManager.hpp"
#include "fileConfig.hpp"

MusicManager::MusicManager(std::string const &musicsFile)
{
    loadMusics(musicsFile);
}

AMusic MusicManager::at(std::string const &index) const
{
    return _musics.at(index);
}

void MusicManager::loadMusics(std::string const &filepath)
{
    nlohmann::json jsonData;
    try {
        jsonData = getJsonData(filepath);
    } catch (std::exception const &e) {
        std::cerr << e.what() << std::endl;
        return;
    }
    for (auto oneData : jsonData) {
        _musics.emplace(oneData.value("title", "menu-music"), AMusic(oneData));
    }
}
