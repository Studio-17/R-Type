/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** loadButton
*/

#include "fileConfig.hpp"
#include <iostream>

void loadButton(std::string const &filepath)
{
    nlohmann::json jsonData;

    try {
        jsonData = getJsonData(filepath);
    } catch (std::exception const &e) {
        std::cerr << e.what() << std::endl;
        return;
    }
    // _rectangle.nb_frames = jsonData.value("nbFrame", 1);

}