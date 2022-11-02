/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** CNetworkQueue
*/

#ifndef CNETWORKQUEUE_HPP_
    #define CNETWORKQUEUE_HPP_

    #include <queue>

    #include "Move.hpp"
    #include "Shoot.hpp"
    #include "NewConnection.hpp"
    #include "Disconnection.hpp"
    #include "Lobbies.hpp"

using byte = unsigned char;

/**
 * @brief A namespace for all components
 */
namespace component {
    /**
     * @brief A structure representing the queue use by the ECS to send the request to the server
     */
    typedef struct cnetwork_queue_s {
        std::queue<std::pair<int, std::vector<byte>>> receivedNetworkQueue;
        std::queue<std::pair<int, std::vector<byte>>> toSendNetworkQueue;

        std::queue<std::pair<int, packet_move>> moveQueue;
        std::queue<std::pair<int, packet_shoot>> shootQueue;
        std::queue<std::pair<int, packet_new_connection>> newPlayerQueue;
        std::queue<std::pair<int, packet_disconnection>> disconnectionQueue;
        std::queue<std::pair<int, packet_join_lobby>> joinLobbyQueue;

    } cnetwork_queue_t;
}

#endif /* !CNETWORKQUEUE_HPP_ */
