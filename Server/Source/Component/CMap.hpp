/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** CMap
*/

#ifndef CMAP_HPP_
    #define CMAP_HPP_

    #include <string>
/**
 * @brief Namespace for all components
 */
namespace component {
    /**
     * @brief A structure representing the direction component that holds the direction of an entity
     */
    struct cmap_t {
        std::string map; ///< Map of enemy
        std::size_t index; ///< Current index in map
        bool end; ///< is this the end of the map
    };
}

#endif /* !CMAP_HPP_ */
