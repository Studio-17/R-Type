/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Health
*/

#ifndef HEALTH_HPP_
    #define HEALTH_HPP_

    #include <iostream>

/**
 * @brief Namespace for all components
 * 
 */
namespace component {
    /**
     * @brief A structure representing the health component that holds the healt of the entity
     * 
     */
    typedef struct health_s {
        size_t health;
    } health_t;
}

#endif /* !HEALTH_HPP_ */
