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
 * 
 */
namespace component {
    /**
     * @brief A structure representing the rectangle component that holds the rectangle of an entity
     * 
     */
    struct crect_t {
        float x;
        float y;
        float width;
        float height;
        int current_frame;
        int nb_frames;
    };
}
#endif /* !CRECT_HPP_ */
