/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Created by casimir,
*/

#ifndef R_TYPE_POSITION_HPP
    #define R_TYPE_POSITION_HPP

    #include <cstdint>

/**
 * @brief A packet to handle the position of an entity in the game area
 */
struct packet_position {
    uint16_t id; ///< Id of the entity to update position
    float x; ///< Position x
    float y; ///< Position y
    uint16_t index; // For 3D effect
};

#endif //R_TYPE_POSITION_HPP
