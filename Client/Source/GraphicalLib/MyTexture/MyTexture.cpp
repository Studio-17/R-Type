/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** MyTexture
*/

#include <iostream>
#include "MyTexture.hpp"

MyTexture::MyTexture(std::string const &texturePath) :
    _texture(LoadTexture(texturePath.c_str()))
{
}

MyTexture::~MyTexture()
{
}

Texture2D MyTexture::getTexture() const
{
    return _texture;
}

int MyTexture::getWidth() const
{
    return _texture.width;
}

int MyTexture::getHeight() const
{
    return _texture.height;
}
