/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Asset
*/

#include <array>
#include <iostream>

#include "Asset.hpp"

Asset::Asset(nlohmann::json const &jsonData) :
    _texture(jsonData.value("texture", "Assets/Images/Sprites/bullet.png")), _scale(jsonData.value("Scale", 1.0))
{
    _rectangle.nb_frames = jsonData.value("nbFrame", 1);
    _rectangle.current_frame = 1;
    _rectangle.x = 0;
    _rectangle.y = 0;
    _rectangle.width = _texture.getWidth() / _rectangle.nb_frames;
    _rectangle.height = _texture.getHeight();
}

Asset::~Asset()
{
}

MyTexture &Asset::getTexture()
{
    return _texture;
}

float Asset::getScale() const
{
    return _scale;
}

component::crect_t Asset::getRectangle() const
{
    return _rectangle;
}

