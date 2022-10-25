/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Asset
*/

#include <array>

#include "Asset.hpp"

Asset::Asset(nlohmann::json const &jsonData) :
    _texture(jsonData.value("texture", "")), _scale(jsonData.value("scale", 1.0))
{
    _rectangle.nb_frames = jsonData.value("nbFrame", 1);
    std::pair<float, float> size = _texture.getSize();
    _rectangle.width = size.first / _rectangle.nb_frames;
    _rectangle.height = size.second / _rectangle.nb_frames;
}

Asset::~Asset()
{
}