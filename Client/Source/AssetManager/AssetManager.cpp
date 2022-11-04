/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** AssetManager
*/

#include <string>
#include <fstream>
#include <exception>
#include <iostream>

#include "AssetManager.hpp"
#include "fileConfig.hpp"

AssetManager::AssetManager(std::string const &assetsFile)
{
    loadAssets(assetsFile);
    // saveAssets(assetsFile);
}

AssetManager::AssetManager()
{

}

AssetManager::~AssetManager()
{
}

Asset AssetManager::at(std::string const &index) const
{
    return _assets.at(index);
}

void AssetManager::loadAssets(std::string const &filepath)
{
    nlohmann::json jsonData;

    try {

        jsonData = getJsonData(filepath);
    } catch (std::exception const &e) {
        std::cerr << e.what() << std::endl;
        return;
    }
    for (auto oneData : jsonData) {
        _assets.emplace(oneData.value("title", "redSpaceShip"), Asset(oneData));
    }
}
