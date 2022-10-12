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
 *
 */
namespace component {
    /**
     * @brief A structure representing the hitbox component that holds the hitbox of the entity
     *
     */
    typedef struct chitbox_s {
        size_t height;
        size_t width;
    } chitbox_t;
}

#endif //R_TYPE_CHITBOX_HPP
