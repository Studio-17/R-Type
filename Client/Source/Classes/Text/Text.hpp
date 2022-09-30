/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Text
*/

#ifndef TEXT_HPP_
#define TEXT_HPP_

#include <string>
#include "Position.hpp"

class Text {
    public:

            Text();

            Text(std::string const &filename, std::string const &text, Position const &position);

            Text(std::string const &filename, std::string const &text, Color const &color, Position const &position = {0, 0});

            Text(std::string const &filename, std::string const &text, int fontSize, Color const &color, Position const &position = {0, 0});

            ~Text();

            void draw() override;

            void enable() override;
            void disable() override;
            bool isEnable() const override;

            void setPosition(Position const &position) override;
            void setPosition(float x, float y) override;
            void setPosition(float x, float y, float z) override;
            Position getPosition() const override;

            void drawFramePerSeconds(Position const &position);

            std::string getText() const;
            void setText(std::string const &text = "");

            void setColor(Color const &color);
            void setFontSize(int fontSize);

    protected:
    private:
        Position _position;
        Font _font;
        Color _color;

        std::string _text;
        int _fontSize = 20;
};

#endif /* !TEXT_HPP_ */
