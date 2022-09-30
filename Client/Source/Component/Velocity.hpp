/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Velocity
*/

#ifndef VELOCITY_HPP_
    #define VELOCITY_HPP_

    #include <iostream>

/**
 * @brief Namespace for all components
 * 
 */
namespace component {
    /**
     * @brief A structure representing the velocity component that holds the velocity of an entity
     * 
     */
    typedef struct velocity_s {
        size_t velocity;
    } velocity_t;
}

#endif /* !VELOCITY_HPP_ */
