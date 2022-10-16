/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Created by casimir,
*/

#ifndef R_TYPE_POSITION_HPP
#define R_TYPE_POSITION_HPP

#include <cstdint>

struct packet_position {
    uint16_t id; // id of the entity to update position
    uint16_t x;
    uint16_t y;
    uint16_t index; // for 3D effect
};

#endif //R_TYPE_POSITION_HPP
