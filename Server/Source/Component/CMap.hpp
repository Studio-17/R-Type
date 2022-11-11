/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** CMap
*/

#ifndef CMAP_HPP_
    #define CMAP_HPP_

    #include <string>
    #include <vector>
    #include <unordered_map>

/**
 * @brief Namespace for all components
 */
namespace component {
    /**
     * @brief A structure representing the direction component that holds the direction of an entity
     */
    struct cmap_t {
        std::vector<std::vector<std::string>> map; ///< Map of enemy
        std::unordered_map<std::size_t, std::size_t> index; ///< Current index of each lobby in map
        std::unordered_map<std::size_t, std::size_t> mapIndex; ///< Current index of each lobby if map
        std::unordered_map<std::size_t, bool> end; ///< is this the end of the map
    };
}

#endif /* !CMAP_HPP_ */
