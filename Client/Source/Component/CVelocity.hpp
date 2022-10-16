/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** CVelocity
*/

#ifndef CVELOCITY_HPP_
    #define CVELOCITY_HPP_

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
    typedef struct cvelocity_s {
        int velocity;
    } cvelocity_t;
}

#endif /* !CVELOCITY_HPP_ */
