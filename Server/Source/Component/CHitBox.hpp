/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Created by casimir,
*/

#ifndef R_TYPE_CHITBOX_HPP
    #define R_TYPE_CHITBOX_HPP

/**
 * @brief Namespace for all components
 */
namespace component {
    /**
     * @brief A structure representing the hitbox component that holds the hitbox of the entity
     */
    struct chitbox_t {
        size_t height; ///< height of the hitbox of the entity
        size_t width; ///< width of the hitbox of the entity
    };
}

#endif //R_TYPE_CHITBOX_HPP
