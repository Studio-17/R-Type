/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Direction
*/

#ifndef DIRECTION_HPP_
    #define DIRECTION_HPP_

    #include <iostream>

/**
 * @brief Namespace for all components
 * 
 */
namespace component {
    /**
     * @brief A structure representing the direction component that holds the direction of an entity
     * 
     */
    typedef struct direction_s {
        size_t x;
        size_t y;
    } direction_t;
}

#endif /* !DIRECTION_HPP_ */
