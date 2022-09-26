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
        ~Sprite();

        float getScale() const;
        void setScale(const Vector2f &scale);

        float getRotation() const;
        void setRotation(float rotation);

        void getOrigin() const;
        void setOrigin(const Vector2f &origin);

        void getPosition() const;
        void setPosition(const Vector2f &position);

        void rotate(float angle);

    protected:
    private:
};

#endif /* !SPRITE_HPP_ */
