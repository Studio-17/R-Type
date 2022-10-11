/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Sprite
*/

#ifndef CSPRITE_HPP_
    #define CSPRITE_HPP_

    #include <iostream>
    #include <string>

    #include "Sprite.hpp"

/**
 * @brief Namespace for all components
 * 
 */
namespace component {
    /**
     * @brief A structure representing the sprite component that holds the sprite properties of a entity
     * 
     */
    typedef struct csprite_s {
        Sprite sprite;
        //float scale;
        //size_t xRect;
        //size_t yRect;
        //size_t widthRect;
        //size_t heightRect;
        //std::string spritePath;
    } csprite_t;
}

#endif /* !CSPRITE_HPP_ */
