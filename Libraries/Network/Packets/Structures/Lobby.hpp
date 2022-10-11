/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Created by casimir,
*/

#ifndef R_TYPE_LOBBY_HPP
#define R_TYPE_LOBBY_HPP

#include <cstdint>

struct packet_create_lobby {
    uint16_t lobby_id;
};

struct packet_join_lobby {
    uint16_t status; // 0:JOIN;1:LEFT
    uint16_t lobby_id;
};

struct packet_lobby_allow { // RESPONSE FOR ABOVE
    uint16_t status; // O:OK;1:KO
};

struct packet_lobby_info {
    uint16_t player1; // 0:OK;1:KO
    uint16_t player2; // 0:OK;1:KO
    uint16_t player3; // 0:OK;1:KO
    uint16_t player4; // 0:OK;1:KO
};

#endif //R_TYPE_LOBBY_HPP
