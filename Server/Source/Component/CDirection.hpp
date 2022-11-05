/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** CDirection
*/

#ifndef CDIRECTION_HPP_
    #define CDIRECTION_HPP_

/**
 * @brief Namespace for all components
 */
namespace component {
    /**
     * @brief A structure representing the direction component that holds the direction of an entity
     */
    typedef struct cdirection_s {
        int x; ///< direction in x line of the entity
        int y; ///< direction in y line of the entity
    } cdirection_t;
}

#endif /* !CDIRECTION_HPP_ */
