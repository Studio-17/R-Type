/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** NewEntity
*/

#ifndef NEWENTITY_HPP_
#   define NEWENTITY_HPP_

    #include <cstdint>

/**
 * @brief A packet to handle a new entity informations
 * 
 */
struct packet_new_entity {
    uint16_t id; // id of new entity;
    float positionX; // x position of new entity;
    float positionY; // y position of new entity;
    uint16_t direction; // direction of new entity;
    uint16_t type; // type of entity;
};

#endif /* !NEWENTITY_HPP_ */
