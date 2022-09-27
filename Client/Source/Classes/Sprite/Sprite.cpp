/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Sprite
*/

#include "Sprite.hpp"

Sprite::Sprite() : _isEnable(false), _imageLoaded(false), _rotation(0.0)
{
}

Sprite::Sprite(std::string const &imagePath, Position const &position) :  _isEnable(true), _imageLoaded(true), _imagePosition(position),
    _imageTexture(LoadTexture(imagePath.c_str())),
    _rotation(0.0f)
{
}

Sprite::~Sprite()
{
    if (_imageLoaded)
        UnloadTexture(_imageTexture);
}

void Sprite::draw()
{
    if (_isEnable)
        DrawTextureEx(_imageTexture, (Vector2){_imagePosition.getX(), _imagePosition.getY()}, _rotation, _imageScale, WHITE);
}


void Sprite::setPosition(Position const &position)
{
    _imagePosition = position;
}

void Sprite::setPosition(float x, float y)
{
    _imagePosition.setPosition(x, y);
}

void Sprite::setScale(float scale)
{
    _imageScale = scale;
}

Position Sprite::getPosition() const
{
    return _imagePosition;
}

void Sprite::setRotation(float rotation)
{
    _rotation = rotation;
}

float Sprite::getRotation() const
{
    return _rotation;
}