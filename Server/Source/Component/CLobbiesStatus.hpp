/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** CLobbyStatus
*/

#ifndef CLOBBYSTATUS_HPP_
    #define CLOBBYSTATUS_HPP_

    #include <unordered_map>

/**
 * @brief Namespace for all components
 */
namespace component {
    /**
     * @brief A structure representing the status of every lobby component that holds the status of every lobby
     */
    struct clobbies_status_t {
        std::unordered_map<int, std::pair<bool, int>> lobbiesStatus; ///< A map that makes correspond an id of lobby to a boolean status : 0 : not in a game, 1 : in a game
    };
}

#endif /* !CLOBBYSTATUS_HPP_ */
