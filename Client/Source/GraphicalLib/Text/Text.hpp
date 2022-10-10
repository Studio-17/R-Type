/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Text
*/

#ifndef TEXT_HPP_
#define TEXT_HPP_

#include <string>
#include "Datas/Position/Position.hpp"

class Text {
    public:
        Text(std::string const &filename, std::string const &text, int fontSize, Color const &color, Position const &position);
        ~Text();

        void draw();

        void setPosition(Position const &position);
        Position getPosition();

        void setText(std::string const &text);
        std::string getText();

        void setFontSize(int fontSize);

        void setColor(Color const &color);

    protected:
    private:
        Position _position;
        Font _font;

        Color _color;
        int _greenColor;
        int _redColor;
        int _blueColor;
        int _alphaColor;

        std::string _text;
        int _fontSize = 20;
};

#endif /* !TEXT_HPP_ */
