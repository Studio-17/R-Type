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

class Sprite {
    public:
        Sprite(std::string const &imagePath, Position const &position, float const &scale);
        ~Sprite();

        void draw();

        void setPosition(Position const &position);
        Position getPosition();

        void setScale(float scale);
        float getScale();

        void setRotation(float rotation);
        float getRotation();

        void setTexture(std::string const &imagePath);

    protected:
    private:
        Position _position;
        float _scale;
        float _rotation;
        Texture2D _imageTexture;
};

#endif /* !SPRITE_HPP_ */
