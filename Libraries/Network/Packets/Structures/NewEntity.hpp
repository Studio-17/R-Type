/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** NewEntity
*/

#ifndef NEWENTITY_HPP_
#   define NEWENTITY_HPP_

    #include <cstdint>

struct packet_new_entity {
    uint16_t id; // id of new entity;
    uint16_t positionX; // x position of new entity;
    uint16_t positionY; // y position of new entity;
    uint16_t direction; // direction of new entity;
    uint16_t type; // type of entity;
};

#endif /* !NEWENTITY_HPP_ */
