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

class Sprite {
    public:
        Sprite(std::string const &imagePath, Position const &position, float const &scale);
        ~Sprite();

        void drawSprite();

        void setPosition(Position const &position);
        float getPosition();

        void setScale(float scale);
        float getScale();

        float setRotation(float rotation);
        void getRotation();

        void setTexture(std::string const &imagePath);

    protected:
    private:
        Position _position;
        float _scale;
        float _rotation;
        Texture2D _imageTexture;
};

#endif /* !SPRITE_HPP_ */
