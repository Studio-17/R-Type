/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** CLobbysToEntities.
*/

#ifndef CLOBBYSTOENTITIES__HPP_
    #define CLOBBYSTOENTITIES__HPP_

    #include <unordered_map>
    #include <vector>
    #include "Entity.hpp"

/**
 * @brief A namespace for all components
 */
namespace component {
    /**
     * @brief A structure representing the Entities contained in lobbies
     */
    struct clobbies_to_entities_t {
        std::unordered_map<int, std::vector<Entity>> lobbiesToEntities; ///< map containing entities of each lobby
    };
}

#endif /* !CLOBBYSTOENTITIES__HPP_ */
