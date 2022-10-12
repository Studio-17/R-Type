/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Sprite
*/

#include "Sprite.hpp"

Sprite::Sprite(std::string const &imagePath, float const &scale, Rectangle const &rect)
{
    _texture = LoadTexture(imagePath.c_str());
    _rotation = 0.0f;
    _scale = scale;
}

Sprite::~Sprite()
{
}

void Sprite::setScale(float scale)
{
    _scale = scale;
}

float Sprite::getScale()
{
    return _scale;
}

void Sprite::setPosition(Position const &position)
{
    _position = position;
}

Position Sprite::getPosition() const
{
    return _position;
}

float Sprite::getHeight()
{
    return _texture.height;
}

float Sprite::getWidth()
{
    return _texture.width;
}

void Sprite::setRotation(float rotation)
{
    _rotation = rotation;
}

float Sprite::getRotation() const
{
    return _rotation;
}

void Sprite::setTexture(std::string const &imagePath)
{
    _texture = LoadTexture(imagePath.c_str());
}

Texture2D Sprite::getTexture() const
{
    return _texture;
}
