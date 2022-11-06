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
        float x; ///< Position x inside the rectangle
        float y; ///< Position y inside the rectangle
        float width; ///< Width of the rectangle
        float height; ///< Height of the rectangle
        int current_frame; ///< Current frame in the rectangle
        int nb_frames; ///< Number of frame in the rectangle
    };
}
#endif /* !CRECT_HPP_ */
