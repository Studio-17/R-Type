/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** CId
*/

#ifndef CSERVERID_HPP_
    #define CSERVERID_HPP_

    #include <cstdint>

/**
 * @brief Namespace for all components
 */
namespace component {
    /**
     * @brief Structure representing the server id component in charge of entity identification
     */
    struct cserverid_t {
        uint16_t id; ///< Id of the entity in server
    };
}

#endif /* !CSERVERID_HPP_ */
