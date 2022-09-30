/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Sprite
*/

#ifndef SPRITE_HPP_
#define SPRITE_HPP_

#include <raylib.h>

class Sprite {
    public:
        Sprite();
        Sprite(std::string const &imagePath, Position const &position = {0, 0});

        ~Sprite();

        void draw();

        void Sprite::setPosition(Position const &position);

        void Sprite::setPosition(float x, float y);

        void Sprite::setScale(float scale);

        Position Sprite::getPosition() const;

        void Sprite::setRotation(float rotation);

        float Sprite::getRotation() const;

    protected:
    private:
        bool _isEnable;
        bool _imageLoaded;
        Position _imagePosition;
        Texture2D _imageTexture;
        float _imageScale = 1.0f;
        float _rotation;
};

#endif /* !SPRITE_HPP_ */
