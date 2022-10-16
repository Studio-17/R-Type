/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Created by casimir,
*/

#ifndef R_TYPE_LOBBY_HPP
#define R_TYPE_LOBBY_HPP

#include <cstdint>

/**
 * @brief A packet to handle the creation of a lobby
 * 
 */
struct packet_create_lobby {
    uint16_t lobby_id;
};

/**
 * @brief A packet to handle a player that joins a lobby
 * 
 */
struct packet_join_lobby {
    uint16_t status; // 0:JOIN;1:LEFT
    uint16_t lobby_id;
};

/**
 * @brief A packet to handle if a player can join a lobby
 * 
 */
struct packet_lobby_allow { // RESPONSE FOR ABOVE
    uint16_t status; // O:OK;1:KO
};

/**
 * @brief A packet to handle the lobby informations
 * 
 */
struct packet_lobby_info {
    uint16_t player1; // 0:OK;1:KO
    uint16_t player2; // 0:OK;1:KO
    uint16_t player3; // 0:OK;1:KO
    uint16_t player4; // 0:OK;1:KO
};

#endif //R_TYPE_LOBBY_HPP
