/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Position
*/

#ifndef POSITION_HPP_
    #define POSITION_HPP_

    #include <iostream>

/**
 * @brief Namespace for all components
 * 
 */
namespace component {
    /**
     * @brief A structure representing the position component that holds the position of an entity
     * 
     */
    typedef struct position_s {
        size_t x;
        size_t y;
    } position_t;
}

#endif /* !POSITION_HPP_ */
