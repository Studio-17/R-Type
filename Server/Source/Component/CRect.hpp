/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** CRect
*/

#ifndef CRECT_HPP_
    #define CRECT_HPP_

/**
 * @brief Namespace for all components
 */
namespace component {
    /**
     * @brief A structure representing the rectangle component that holds the rectangle of an entity
     */
    struct crect_t {
        float height; ///< height of the rect of the entity
        float width; ///< width of the rect of the entity
    };
}

#endif /* !CRECT_HPP_ */