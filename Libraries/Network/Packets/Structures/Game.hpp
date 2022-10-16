/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Created by casimir,
*/

#ifndef R_TYPE_GAME_HPP
#define R_TYPE_GAME_HPP

#include <cstdint>

/**
 * @brief A packet to handle the game current status
 * 
 */
struct packet_game {
    uint16_t status; // 0:STARTING;1:RUNNING;2:STOPPED
};

#endif //R_TYPE_GAME_HPP
