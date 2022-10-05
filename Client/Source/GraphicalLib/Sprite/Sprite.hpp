/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Sprite
*/

#ifndef SPRITE_HPP_
#define SPRITE_HPP_

#include <iostream>
#include "Position.hpp"

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
         * @param position 
         * @param scale 
         */
        Sprite(std::string const &imagePath, Position const &position, float const &scale);
        /**
         * @brief Destroy the Sprite object
         * 
         */
        ~Sprite();

        /**
         * @brief Draw the sprite
         * 
         */
        void draw();

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
        Position getPosition();

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
        float getRotation();
        /**
         * @brief Set the Texture of the sprite
         * 
         * @param imagePath 
         */
        void setTexture(std::string const &imagePath);

    protected:
    private:
        Position _position; ///< Position of the sprite
        float _scale; ///< Scale of the sprite
        float _rotation; ///< Rotation of the sprite
        Texture2D _imageTexture; ///< Texture of the sprite
};

#endif /* !SPRITE_HPP_ */
