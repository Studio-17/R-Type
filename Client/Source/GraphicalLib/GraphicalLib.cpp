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

void rtype::GraphicalLib::createText(std::size_t id, std::string const &filename, std::string const &text, int fontSize, Color const &color, Position const &position)
{
    _textMap[id].reset(new Text(filename, text, fontSize, color, position));
}

void rtype::GraphicalLib::drawText(std::size_t id)
{
    _textMap[id]->draw();
}

void rtype::GraphicalLib::setTextPosition(std::size_t id, Position const &position)
{
    _textMap[id]->setPosition(position);
}

Position rtype::GraphicalLib::getTextPosition(std::size_t id)
{
    return _textMap[id]->getPosition();
}

std::string rtype::GraphicalLib::getText(std::size_t id)
{
    return _textMap[id]->getText();
}

void rtype::GraphicalLib::setText(std::size_t id, std::string const &text)
{
    _textMap[id]->setText(text);
}

void rtype::GraphicalLib::setTextColor(std::size_t id, Color const &color)
{
    _textMap[id]->setColor(color);
}

void rtype::GraphicalLib::setTextFontSize(std::size_t id, int fontSize)
{
    _textMap[id]->setFontSize(fontSize);
}
