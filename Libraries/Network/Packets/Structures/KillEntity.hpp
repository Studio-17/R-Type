/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** KillEntity
*/

#ifndef KILLENTITY_HPP_
    #define KILLENTITY_HPP_

    #include <cstdint>

/**
 * @brief A packet to handle the killing of an entity
 */
struct packet_kill_entity {
    int id; ///< Id of the entity to kill (this is the server Id of the Entity)
};

#endif /* !KILLENTITY_HPP_ */
