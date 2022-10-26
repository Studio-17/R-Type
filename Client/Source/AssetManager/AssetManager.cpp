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

AssetManager::AssetManager(std::string const &assetsFile)
{
    loadAssets(assetsFile);
    // saveAssets(assetsFile);
}

AssetManager::~AssetManager()
{
}


nlohmann::json AssetManager::getJsonData(std::string const &filepath)
{
    nlohmann::json jsonData;
    std::ifstream confStream(filepath);

    if (!confStream.is_open())
        throw ("file " + filepath + " failed to open");
    confStream >> jsonData;
    confStream.close();
    return jsonData;
}

void AssetManager::loadAssets(std::string const &filepath)
{
    nlohmann::json jsonData;
    std::size_t id = 0;

    try {
        jsonData = getJsonData(filepath);
    } catch (std::exception const &e) {
        std::cerr << e.what() << std::endl;
        return;
    }
    for (auto oneData : jsonData) {
        _assets.emplace(oneData.value("id", id), Asset(oneData));
        id++;
    }
}

void AssetManager::saveAssets(std::string const &filepath)
{
    // nlohmann::json saveData = getJsonData(filepath);
    nlohmann::json saveData;
    std::ofstream fileToWrite(filepath);

    if (!fileToWrite.is_open())
        throw ("File " + filepath + " failed to open");

    saveData["Asset1"]["id"] = 1;
    saveData["Asset1"]["texture"] = "test";
    fileToWrite << saveData.dump(4);
}
