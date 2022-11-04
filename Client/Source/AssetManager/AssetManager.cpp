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
    // std::cout << "AssetManager" << std::endl;
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
        // std::cout << oneData << std::endl;
        // std::cout << oneData.value("title", "redSpaceShip") << std::endl;
        // std::cout << "COLL" << std::endl;
    }
    // std::cout << "In" << std::endl;
    // std::cout << _assets.size() << std::endl;
}

// void AssetManager::saveAssets(std::string const &filepath)
// {
//     // nlohmann::json saveData = getJsonData(filepath);
//     nlohmann::json saveData;
//     std::ofstream fileToWrite(filepath);

//     if (!fileToWrite.is_open())
//         throw ("File " + filepath + " failed to open");

//     saveData["player"]["id"] = 1;
//     saveData["player"]["texture"] = "Assets/sprites/r-typesheet42.gif";
//     saveData["player"]["scale"] = 1;
//     saveData["player"]["nbFrame"] = 5;
//     saveData["bullet"]["id"] = 1;
//     saveData["bullet"]["texture"] = "Assets/sprites/bullet.png";
//     saveData["bullet"]["scale"] = 1;
//     saveData["bullet"]["nbFrame"] = 2;
//     saveData["enemy"]["id"] = 1;
//     saveData["enemy"]["texture"] = "Assets/sprites/BasicEnemySpriteSheet.gif";
//     saveData["enemy"]["scale"] = 1;
//     saveData["enemy"]["nbFrame"] = 8;
//     fileToWrite << saveData.dump(4);
// }
