/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Sprite
*/

#ifndef SPRITE_HPP_
#define SPRITE_HPP_

    #include <iostream>
    #include <string>
    #include "Datas/Position/Position.hpp"

/**
 * @brief Sprite class
 *
 */
class Sprite {
    public:
        /**
         * @brief Construct a new Sprite object
         *
         * @param imagePath
         * @param scale
         */
        Sprite(std::string const &imagePath, float const &scale, Rectangle const &rect);
        /**
         * @brief Destroy the Sprite object
         *
         */
        ~Sprite();

        /**
         * @brief Set the Position of the sprite
         *
         * @param position
         */
        void setPosition(Position const &position);
        /**
         * @brief Get the Position of the sprite
         *
         * @return Position
         */
        Position getPosition() const;

        /**
         * @brief Get the Width of the sprite
         *
         * @param rotation
         */
        float getWidth();
        /**
         * @brief Get the Height of the sprite
         *
         * @return float
         */
        float getHeight();

        /**
         * @brief Set the Scale of the sprite
         *
         * @param scale
         */
        void setScale(float scale);
        /**
         * @brief Get the Scale of the sprite
         *
         * @return float
         */
        float getScale();

        /**
         * @brief Set the Rotation of the sprite
         *
         * @param rotation
         */
        void setRotation(float rotation);
        /**
         * @brief Get the Rotation of the sprite
         *
         * @return float
         */
        float getRotation() const;
        /**
         * @brief Set the Texture of the sprite
         *
         * @param imagePath
         */
        void setTexture(std::string const &imagePath);
        /**
         * @brief Get the Texture of the sprite
         *
         * @return std::string
         */
        Texture2D getTexture() const;

    protected:
    private:
        Position _position; ///< Position of the sprite
        float _scale; ///< Scale of the sprite
        float _rotation; ///< Rotation of the sprite
        Texture2D _texture; ///< Texture of the sprite
};

#endif /* !SPRITE_HPP_ */
