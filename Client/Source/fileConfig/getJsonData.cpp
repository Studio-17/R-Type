/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-martin.vanaud
** File description:
** getJsonData
*/

#include <nlohmann/json.hpp>

#include <iostream>
#include <fstream>

nlohmann::json getJsonData(std::string const &filepath)
{
    nlohmann::json jsonData;
    std::ifstream confStream(filepath);

    if (!confStream.is_open()) {
        throw ("file " + filepath + " failed to open");
    }
    confStream >> jsonData;
    confStream.close();
    return jsonData;
}