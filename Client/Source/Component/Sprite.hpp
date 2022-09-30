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

/**
 * @brief Namespace for all components
 * 
 */
namespace component {
    /**
     * @brief A structure representing the sprite component that holds the sprite properties of a entity
     * 
     */
    typedef struct sprite_s {
        float scale;
        size_t xRect;
        size_t yRect;
        size_t widthRect;
        size_t heightRect;
        std::string spritePath;
    } sprite_t;
}

#endif /* !SPRITE_HPP_ */
