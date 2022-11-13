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

/**
 * @brief MyTexture class
 *
 */
class MyTexture {
    public:
        /**
         * @brief Construct a new My Texture object
         *
         * @param texturePath path to the texture
         */
        MyTexture(std::string const &texturePath);
        /**
         * @brief Destroy the My Texture object
         *
         */
        ~MyTexture();

        /**
         * @brief Get the Texture object
         *
         * @return Texture2D texture
         */
        Texture2D getTexture() const;
        /**
         * @brief Get the Width object
         *
         * @return int witdh
         */
        int getWidth() const;
        /**
         * @brief Get the Height object
         *
         * @return int height
         */
        int getHeight() const;

    protected:
    private:
        Texture2D _texture; ///< Texture of the sprite

};

#endif /* !MYTEXTURE_HPP_ */
