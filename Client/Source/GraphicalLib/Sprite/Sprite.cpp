/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Sprite
*/

#include "Sprite.hpp"

Sprite::Sprite(std::string const &imagePath, Position const &position, float const &scale)
{
    _position = position;
    _imageTexture = LoadTexture(imagePath.c_str());
    _rotation = 0.0f;
    _scale = scale;
}

Sprite::~Sprite()
{
    UnloadTexture(_imageTexture);
}

void Sprite::draw()
{
    DrawTextureEx(_imageTexture, (Vector2){_position.getX(), _position.getY()}, _rotation, _scale, WHITE);
}

void Sprite::setPosition(Position const &position)
{
    _position = position;
}

Position Sprite::getPosition()
{
    return _position;
}

void Sprite::setScale(float scale)
{
    _scale = scale;
}

float Sprite::getScale()
{
    return _scale;
}

void Sprite::setRotation(float rotation)
{
    _rotation = rotation;
}

float Sprite::getRotation()
{
    return _rotation;
}

void Sprite::setTexture(std::string const &imagePath)
{
    _imageTexture = LoadTexture(imagePath.c_str());
}
