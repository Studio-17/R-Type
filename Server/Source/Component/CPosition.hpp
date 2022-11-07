/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Position
*/

#ifndef CPOSITION_HPP_
    #define CPOSITION_HPP_

/**
 * @brief Namespace for all components
 */
namespace component {
    /**
     * @brief A structure representing the position component that holds the position of an entity
     */
    struct cposition_t {
        float x; ///< position x of the entity
        float y; ///< position y of the entity
    };
}

#endif /* !CPOSITION_HPP_ */
