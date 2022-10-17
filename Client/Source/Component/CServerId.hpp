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
 *
 */
namespace component {
    /**
     * @brief Structure representing the server id component in charge of entity identification
     *
     */
    typedef struct cserverid_s {
        uint16_t id;
    } cserverid_t;
}

#endif /* !CSERVERID_HPP_ */
