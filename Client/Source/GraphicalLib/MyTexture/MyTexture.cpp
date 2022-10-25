/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** MyTexture
*/

#include "MyTexture.hpp"

MyTexture::MyTexture(std::string const &texturePath) :
    _texture(LoadTexture(texturePath.c_str()))
{
}

MyTexture::~MyTexture()
{
}

Texture2D &MyTexture::getTexture()
{
    return _texture;
}

std::pair<int, int> MyTexture::getSize()
{
    int width = _texture.width;
    int height = _texture.height;
    std::pair<int, int> sz(width, height);
    return sz;
}
