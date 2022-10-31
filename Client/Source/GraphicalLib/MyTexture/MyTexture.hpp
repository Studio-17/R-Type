/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** MyTexture
*/

#ifndef MYTEXTURE_HPP_
    #define MYTEXTURE_HPP_

    #include <raylib.h>
    #include <string>
    #include <utility>

class MyTexture {
    public:
        MyTexture(std::string const &texturePath);
        MyTexture();
        ~MyTexture();

        Texture2D getTexture() const;
        int getWidth() const;
        int getHeight() const;

    protected:
    private:
        Texture2D _texture; ///< Texture of the sprite

};

#endif /* !MYTEXTURE_HPP_ */
