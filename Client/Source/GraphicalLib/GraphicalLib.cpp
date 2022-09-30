/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** GraphicalLib
*/

#include "GraphicalLib.hpp"

rtype::GraphicalLib::GraphicalLib(const int screenWidth, const int screenHeight, std::string title, const int framerate)
{
    InitWindow(screenWidth, screenHeight, title.c_str());
    _spriteMap = {};
    _textMap = {};
    _soundMap = {};
    _musicMap = {};

    SetTargetFPS(framerate);
}

rtype::GraphicalLib::~GraphicalLib()
{
}
