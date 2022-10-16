/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Position
*/

#ifndef CPOSITION_HPP_
    #define CPOSITION_HPP_

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
    typedef struct cposition_s {
        float x;
        float y;
    } cposition_t;
}

#endif /* !CPOSITION_HPP_ */
