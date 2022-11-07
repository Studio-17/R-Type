/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** CHealth
*/

#ifndef CHEALTH_HPP_
    #define CHEALTH_HPP_

    #include <cstddef>

/**
 * @brief Namespace for all components
 */
namespace component {
    /**
     * @brief A structure representing the health component that holds the healt of the entity
     */
    struct chealth_t {
        std::size_t health; ///< health of the entity
    };
}

#endif /* !CHEALTH_HPP_ */
