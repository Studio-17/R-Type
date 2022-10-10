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

/**
 * @brief Text class
 * 
 */
class Text {
    public:
        /**
         * @brief Construct a new Text object
         * 
         * @param filename 
         * @param text 
         * @param fontSize 
         * @param color 
         * @param position 
         */
        Text(std::string const &filename, std::string const &text, int fontSize, Color const &color, Position const &position);
        /**
         * @brief Destroy the Text object
         * 
         */
        ~Text();

        /**
         * @brief Draw the text
         * 
         */
        void draw();

        /**
         * @brief Set the Position of the text
         * 
         * @param position 
         */
        void setPosition(Position const &position);
        /**
         * @brief Get the Position of the text
         * 
         * @return Position 
         */
        Position getPosition();

        /**
         * @brief Set the Color of the text
         * 
         * @param color 
         */
        void setText(std::string const &text);
        /**
         * @brief Get the Color of the text
         * 
         * @return Color 
         */
        std::string getText();
        /**
         * @brief Set the Color of the text
         * 
         * @param color 
         */
        void setFontSize(int fontSize);
        /**
         * @brief Get the Color of the text
         * 
         * @return Color 
         */
        void setColor(Color const &color);

    protected:
    private:
        Position _position; ///< Position of the text
        Font _font; ///< Font of the text
        Color _color; ///< Color of the text
        std::string _text; ///< Text content
        int _fontSize = 20; ///< Font size of the text
};

#endif /* !TEXT_HPP_ */
