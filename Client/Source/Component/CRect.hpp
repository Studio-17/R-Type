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
    typedef struct crect_s {
        float x;
        float y;
        float height;
        float width;
        int current_frame;
        int nb_frames;
    } crect_t;
}
#endif /* !CRECT_HPP_ */
