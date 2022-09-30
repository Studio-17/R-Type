/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Text
*/

#include "Text.hpp"

Text::Text(std::string const &filename, std::string const &text, int fontSize, Color const &color, Position const &position) : _position(position), _font(LoadFont(filename.c_str())), _color(color), _text(text), _fontSize(fontSize)
{
}

Text::~Text()
{
    UnloadFont(_font);
}

void Text::draw()
{
    DrawText(_text.c_str(), _position.getX(), _position.getY(), _fontSize, _color);
}

void Text::setPosition(Position const &position)
{
    _position = position;
}

Position Text::getPosition()
{
    return _position;
}

void Text::setText(std::string const &text)
{
    _text = text;
}

std::string Text::getText()
{
    return _text;
}

void Text::setFontSize(int fontSize)
{
    _fontSize = fontSize;
}

void Text::setColor(Color const &color)
{
    _color = color;
}
