/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Text
*/

#include "Text.hpp"

Object::Text::Text() :
    _isEnable(true),
    _font(LoadFont("Ressources/fonts/primetime/PRIMETIME.ttf"))
{
}

Object::Text::Text(std::string const &filename, std::string const &text, Position const &position) : _isEnable(true),
 _position(position), _font(LoadFont(filename.c_str())), _text(text)
{

}

Object::Text::Text(std::string const &filename, std::string const &text, Color const &color, Position const &position) : _isEnable(true),
 _position(position), _font(LoadFont(filename.c_str())), _color(color), _text(text)
{

}

Object::Text::Text(std::string const &filename, std::string const &text, int fontSize, Color const &color, Position const &position) : _isEnable(true),
 _position(position), _font(LoadFont(filename.c_str())), _color(color), _text(text), _fontSize(fontSize)
{

}

Object::Text::~Text()
{
    UnloadFont(_font);
}

void Text::draw()
{
    if (_isEnable)
        DrawText(_text.c_str(), _position.getX(), _position.getY(), _fontSize, _color);
}

void Text::enable()
{
    _isEnable = true;
}

void Text::disable()
{
    _isEnable = false;
}

bool Text::isEnable() const
{
    return _isEnable;
}

void Text::setPosition(Position const &position)
{
    _position = position;
}

void Text::setPosition(float x, float y)
{
    _position.setPosition(x, y);
}

void Text::setPosition(float x, float y, float z)
{
    _position.setPosition(x, y, z);
}

Position Text::getPosition() const
{
    return _position;
}

void Text::drawFramePerSeconds(Position const &position)
{
    DrawFPS(position.getX(), position.getY());
}

std::string Text::getText() const
{
    return _text;
}

void Text::setText(std::string const &text)
{
    _text = text;
}

void Text::setColor(Color const &color)
{
    _color = color;
}

void Text::setFontSize(int fontSize)
{
    _fontSize = fontSize;
}